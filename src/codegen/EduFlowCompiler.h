#pragma once
#include "ast/ASTNodes.h"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <memory>
#include <map>

class EduFlowCompiler {
public:
    EduFlowCompiler();
    void compile(const Program& program);
    void dumpIR();
    void executeJIT(const Program& program);
    void optimize(); 

private:
    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder;

    llvm::StructType* getCourseType();
    llvm::StructType* getStudentType();

    void compileCourse(const CourseDef& course);
    void compileRule(const RuleDef& rule);
    llvm::Value* compileExpression(const ExprNode* expr, llvm::Value* argStudent);
};