#pragma once

#include "antlr4-runtime.h"
#include "EduFlowBaseVisitor.h"
#include "EduFlowLexer.h"
#include "EduFlowParser.h"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <any>

using namespace antlr4;
using namespace llvm;
using namespace llvm::orc;

struct CourseInfo {
    std::string id;
    int credits = 0;
    int capacity = 0;
    std::string eligibilityRule;
};

struct StageInfo {
    int max_credits = 99;
};

struct WorkflowInfo {
    std::string id;
    std::vector<StageInfo> stages;
};

struct StudentData {
    std::string id;
    int credits_completed = 0;
};

struct SimulationRequest {
    std::string name;
    std::string workflowId;
    StudentData student;
    std::vector<std::string> coursesToEnroll;
};

struct StudentNative {
    int32_t credits_completed;
};

class EduFlowDriver : public EduFlowBaseVisitor {
private:
    std::unique_ptr<LLVMContext> context;
    std::unique_ptr<Module> module;
    std::unique_ptr<IRBuilder<>> builder;
    
    std::map<std::string, CourseInfo> courses;
    std::map<std::string, WorkflowInfo> workflows;
    std::vector<SimulationRequest> simulations;

    StructType* getStudentType() {
        StructType* type = StructType::getTypeByName(*context, "Student");
        if (type) return type;
        return StructType::create(*context, { Type::getInt32Ty(*context) }, "Student");
    }

public:
    EduFlowDriver() {
        context = std::make_unique<LLVMContext>();
        module = std::make_unique<Module>("EduFlowModule", *context);
        builder = std::make_unique<IRBuilder<>>(*context);
    }

    std::any visitProgram(EduFlowParser::ProgramContext *ctx) override {
        auto result = visitChildren(ctx);
        return result;
    }

    std::any visitCourseDef(EduFlowParser::CourseDefContext *ctx) override {
        CourseInfo c;
        c.id = ctx->ID()->getText();

        for (auto cmd : ctx->courseCommand()) {
            if (cmd->getText().find("credits=") != std::string::npos) {
                c.credits = std::stoi(cmd->INT(0)->getText());
            } else if (cmd->getText().find("eligibility=") != std::string::npos) {
                c.eligibilityRule = cmd->ID()->getText();
            }
        }
        courses[c.id] = c;
        return std::any();
    }

    std::any visitWorkflowDef(EduFlowParser::WorkflowDefContext *ctx) override {
        WorkflowInfo w;
        w.id = ctx->ID()->getText();
        
        for (auto stageCtx : ctx->stageDef()) {
            StageInfo s;
            for (auto cmd : stageCtx->stageCommand()) {
                if (cmd->getText().find("max_credits=") != std::string::npos) {
                    s.max_credits = std::stoi(cmd->INT()->getText());
                }
            }
            w.stages.push_back(s);
        }
        workflows[w.id] = w;
        return std::any();
    }

    std::any visitSimulationDef(EduFlowParser::SimulationDefContext *ctx) override {
        SimulationRequest sim;
        sim.name = ctx->STRING()->getText();
        sim.workflowId = ctx->ID()->getText();

        auto studentCtx = ctx->studentDef();
        for (auto prop : studentCtx->studentProperty()) {
             if (prop->getText().find("id=") != std::string::npos) {
                 sim.student.id = prop->STRING()->getText();
             } else if (prop->getText().find("credits_completed=") != std::string::npos) {
                 sim.student.credits_completed = std::stoi(prop->INT()->getText());
             }
        }

        auto enrollCtx = ctx->enrollmentDef();
        std::string listText = enrollCtx->idList()->getText();
        listText = listText.substr(1, listText.length() - 2);
        
        size_t pos = 0;
        std::string token;
        while ((pos = listText.find(',')) != std::string::npos) {
            token = listText.substr(0, pos);
            sim.coursesToEnroll.push_back(token);
            listText.erase(0, pos + 1);
        }
        if (!listText.empty()) sim.coursesToEnroll.push_back(listText);

        simulations.push_back(sim);
        return std::any();
    }

    std::any visitRuleDef(EduFlowParser::RuleDefContext *ctx) override {
        std::string ruleName = ctx->ID()->getText();
        Type* boolType = Type::getInt1Ty(*context);
        Type* studentPtrType = PointerType::get(getStudentType(), 0);
        
        FunctionType* ft = FunctionType::get(boolType, { studentPtrType }, false);
        Function* function = Function::Create(ft, Function::ExternalLinkage, ruleName, module.get());
        
        BasicBlock* entryBlock = BasicBlock::Create(*context, "entry", function);
        builder->SetInsertPoint(entryBlock);
        
        Value* argStudent = function->getArg(0);
        argStudent->setName("student");

        if (ctx->expression()) {
             Value* result = std::any_cast<Value*>(visitExpressionInternal(ctx->expression(), argStudent));
             
             if (result->getType() != boolType) {
                 result = builder->CreateICmpNE(result, ConstantInt::get(result->getType(), 0), "toBool");
             }
             builder->CreateRet(result);
        } else {
             builder->CreateRet(ConstantInt::get(boolType, 1));
        }

        return std::any();
    }

    Value* visitExpressionInternal(EduFlowParser::ExpressionContext* ctx, Value* argStudent) {
        if (ctx->children.size() == 1) {
            return visitTermInternal(ctx->term(0), argStudent);
        }
        
        Value* left = visitTermInternal(ctx->term(0), argStudent);
        for (size_t i = 1; i < ctx->term().size(); ++i) {
            Value* right = visitTermInternal(ctx->term(i), argStudent);
            std::string op = ctx->LOGICAL_OP(i-1)->getText();
            
            if (op == "AND") left = builder->CreateAnd(left, right, "and_op");
            else if (op == "OR") left = builder->CreateOr(left, right, "or_op");
        }
        return left;
    }

    Value* visitTermInternal(EduFlowParser::TermContext* ctx, Value* argStudent) {
        if (ctx->ID()) {
            return ConstantInt::get(Type::getInt1Ty(*context), 1);
        }
        
        if (ctx->expression()) {
            return visitExpressionInternal(ctx->expression(), argStudent);
        }

        if (ctx->ATTR_ID()) {
            std::string attr = ctx->ATTR_ID()->getText();
            std::string op = ctx->OPERATOR()->getText();
            
            Value* valComparison = nullptr;
            if (ctx->value()->INT()) {
                int val = std::stoi(ctx->value()->INT()->getText());
                valComparison = ConstantInt::get(Type::getInt32Ty(*context), val);
            }

            Value* loadedVal = nullptr;
            if (attr == "student.credits_completed") {
                Value* fieldAddr = builder->CreateStructGEP(getStudentType(), argStudent, 0, "ptr_credits");
                loadedVal = builder->CreateLoad(Type::getInt32Ty(*context), fieldAddr, "credits_val");
            } else {
                loadedVal = ConstantInt::get(Type::getInt32Ty(*context), 0);
            }

            if (op == ">") return builder->CreateICmpSGT(loadedVal, valComparison);
            if (op == ">=") return builder->CreateICmpSGE(loadedVal, valComparison);
            if (op == "<") return builder->CreateICmpSLT(loadedVal, valComparison);
            if (op == "<=") return builder->CreateICmpSLE(loadedVal, valComparison);
            if (op == "==") return builder->CreateICmpEQ(loadedVal, valComparison);
            if (op == "!=") return builder->CreateICmpNE(loadedVal, valComparison);
        }
        return ConstantInt::get(Type::getInt1Ty(*context), 0);
    }

    void dumpIR() {
        module->print(outs(), nullptr);
    }

    void executeSimulations() {
        outs() << "\n--- INICIANDO SIMULACION (JIT) ---\n";

        InitializeNativeTarget();
        InitializeNativeTargetAsmPrinter();
        InitializeNativeTargetAsmParser();

        auto jitExpected = LLJITBuilder().create();
        if (!jitExpected) {
            errs() << "Error creando JIT.\n";
            return;
        }
        auto jit = std::move(*jitExpected);

        ThreadSafeModule tsm(std::move(module), std::move(context));
        if (auto err = jit->addIRModule(std::move(tsm))) {
            errs() << "Error añadiendo modulo al JIT.\n";
            return;
        }

        using RuleFuncPtr = bool(*)(StudentNative*);

        for (const auto& sim : simulations) {
            outs() << ">> Simulacion: " << sim.name << "\n";
            StudentNative nStud { sim.student.credits_completed };
            
            if (workflows.find(sim.workflowId) == workflows.end()) {
                outs() << "   Workflow no encontrado.\n";
                continue;
            }
            WorkflowInfo wf = workflows[sim.workflowId];
            int stageMax = wf.stages.empty() ? 999 : wf.stages[0].max_credits;

            int currentCredits = 0;
            for (const auto& cId : sim.coursesToEnroll) {
                if (courses.find(cId) == courses.end()) {
                    outs() << "   Curso " << cId << " no existe.\n";
                    continue;
                }
                CourseInfo course = courses[cId];

                if (!course.eligibilityRule.empty()) {
                    auto sym = jit->lookup(course.eligibilityRule);
                    if (sym) {
                        auto func = (RuleFuncPtr)sym->getValue();
                        if (!func(&nStud)) {
                            outs() << "   [RECHAZADO] " << cId << " (Regla " << course.eligibilityRule << " fallo)\n";
                            continue;
                        }
                    } else {
                        outs() << "   [ERROR] Regla " << course.eligibilityRule << " no encontrada en JIT.\n";
                        continue;
                    }
                }

                if (currentCredits + course.credits > stageMax) {
                     outs() << "   [RECHAZADO] " << cId << " (Excede creditos de etapa)\n";
                     continue;
                }

                currentCredits += course.credits;
                outs() << "   [APROBADO] " << cId << "\n";
            }
        }
    }
};
