#include "EduFlowCompiler.h"
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetSelect.h>
#include <iostream>

using namespace llvm;
using namespace llvm::orc;

// ==========================================
// 1. INICIALIZACIÓN Y CONFIGURACIÓN
// ==========================================

EduFlowCompiler::EduFlowCompiler() {
    // Inicializamos el contexto global de LLVM, el módulo y el builder
    context = std::make_unique<LLVMContext>();
    module = std::make_unique<Module>("EduFlowModule", *context);
    builder = std::make_unique<IRBuilder<>>(*context);
}

// Definimos la estructura de un Curso: { i32 credits, i32 level }
StructType* EduFlowCompiler::getCourseType() {
    StructType* type = StructType::getTypeByName(*context, "Course");
    if (type) return type;
    return StructType::create(*context, { Type::getInt32Ty(*context), Type::getInt32Ty(*context) }, "Course");
}

// Definimos la estructura de un Estudiante: { i32 credits_completed }
StructType* EduFlowCompiler::getStudentType() {
    StructType* type = StructType::getTypeByName(*context, "Student");
    if (type) return type;
    return StructType::create(*context, { Type::getInt32Ty(*context) }, "Student");
}

// ==========================================
// 2. FASE DE COMPILACIÓN (AST -> LLVM IR)
// ==========================================

void EduFlowCompiler::compile(const Program& program) {
    // Compilamos todas las definiciones estáticas primero
    for (const auto& course : program.courses) {
        compileCourse(*course);
    }
    // Compilamos la lógica de las reglas como funciones
    for (const auto& rule : program.rules) {
        compileRule(*rule);
    }
}

void EduFlowCompiler::compileCourse(const CourseDef& course) {
    StructType* courseType = getCourseType();
    
    // Creamos los valores constantes del struct
    std::vector<Constant*> values = {
        ConstantInt::get(Type::getInt32Ty(*context), course.credits),
        ConstantInt::get(Type::getInt32Ty(*context), course.level)
    };

    // Creamos la variable global
    new GlobalVariable(
        *module,
        courseType,
        true, // es constante
        GlobalValue::ExternalLinkage,
        ConstantStruct::get(courseType, values),
        course.id
    );
}

void EduFlowCompiler::compileRule(const RuleDef& rule) {
    // Firma de la función: bool NombreRegla(Student* s)
    Type* boolType = Type::getInt1Ty(*context);
    Type* studentPtrType = PointerType::get(getStudentType()->getContext(), 0);
    
    FunctionType* ft = FunctionType::get(boolType, { studentPtrType }, false);
    Function* function = Function::Create(ft, Function::ExternalLinkage, rule.id, module.get());

    // Bloque de entrada
    BasicBlock* entryBlock = BasicBlock::Create(*context, "entry", function);
    builder->SetInsertPoint(entryBlock);

    // Argumento 0: Puntero al estudiante
    Value* argStudent = function->getArg(0);
    argStudent->setName("student");

    if (rule.condition) {
        // Generamos el código para evaluar la expresión
        Value* result = compileExpression(rule.condition.get(), argStudent);
        
        // Aseguramos que el resultado sea i1 (booleano)
        if (result->getType() != boolType) {
            result = builder->CreateICmpNE(result, ConstantInt::get(result->getType(), 0), "toBool");
        }
        builder->CreateRet(result);
    } else {
        // Si no hay condición, true por defecto
        builder->CreateRet(ConstantInt::get(boolType, 1));
    }
}

llvm::Value* EduFlowCompiler::compileExpression(const ExprNode* expr, llvm::Value* argStudent) {
    // CASO 1: LITERAL ENTERO
    if (const auto* lit = dynamic_cast<const IntLiteral*>(expr)) {
        return ConstantInt::get(Type::getInt32Ty(*context), lit->value);
    }

    // CASO 2: ACCESO A VARIABLE (student.credits_completed)
    if (const auto* var = dynamic_cast<const VariableAccess*>(expr)) {
        if (var->structName == "student") {
            // Asumimos credits_completed en índice 0
            Value* fieldAddr = builder->CreateStructGEP(getStudentType(), argStudent, 0, "ptr_credits");
            return builder->CreateLoad(Type::getInt32Ty(*context), fieldAddr, "credits_val");
        }
    }

    // CASO 3: OPERACIÓN BINARIA
    if (const auto* bin = dynamic_cast<const BinaryOp*>(expr)) {
        Value* L = compileExpression(bin->left.get(), argStudent);
        Value* R = compileExpression(bin->right.get(), argStudent);

        if (!L || !R) return nullptr;

        if (bin->op == ">=") return builder->CreateICmpSGE(L, R, "cmp_ge");
        if (bin->op == ">")  return builder->CreateICmpSGT(L, R, "cmp_gt");
        if (bin->op == "<=") return builder->CreateICmpSLE(L, R, "cmp_le");
        if (bin->op == "<")  return builder->CreateICmpSLT(L, R, "cmp_lt");
        if (bin->op == "==") return builder->CreateICmpEQ(L, R, "cmp_eq");
        if (bin->op == "!=") return builder->CreateICmpNE(L, R, "cmp_ne");
    }

    return ConstantInt::get(Type::getInt32Ty(*context), 0);
}

#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/StandardInstrumentations.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Scalar/Reassociate.h"
#include "llvm/Transforms/Scalar/SimplifyCFG.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Utils/Mem2Reg.h"         

void EduFlowCompiler::optimize() {
    // 1. Crear los Managers de Análisis y Pasadas
    LoopAnalysisManager LAM;
    FunctionAnalysisManager FAM;
    CGSCCAnalysisManager CGAM;
    ModuleAnalysisManager MAM;

    PassBuilder PB;

    // 2. Registrar los análisis
    PB.registerModuleAnalyses(MAM);
    PB.registerFunctionAnalyses(FAM);
    PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);

    // 3. Crear el Pipeline de optimización de funciones
    FunctionPassManager FPM;
    
    // --- AGREGANDO PASADAS DE OPTIMIZACIÓN ---
    // InstCombine: Combina instrucciones redundantes (ej: x+0 -> x)
    FPM.addPass(InstCombinePass());
    // Reassociate: Reordena expresiones para mejor plegado de constantes
    FPM.addPass(ReassociatePass());
    // GVN: Elimina redundancias globales (Global Value Numbering)
    FPM.addPass(GVNPass());
    // SimplifyCFG: Limpia el grafo de flujo de control (elimina bloques muertos)
    FPM.addPass(SimplifyCFGPass());
    // Mem2Reg: Promueve variables de pila a registros SSA (CRÍTICO para rendimiento)
    // Nota: LLVM genera mucho 'alloca' que Mem2Reg limpia.
    // FPM.addPass(PromotePass()); // Si usaras allocas, pero tu codegen ya usa registros virtuales directos mayormente.

    // 4. Ejecutar las optimizaciones sobre todas las funciones del módulo
    for (auto &F : *module) {
        if (!F.isDeclaration()) {
            FPM.run(F, FAM);
        }
    }
}

void EduFlowCompiler::dumpIR() {
    if (module) module->print(outs(), nullptr);
    else outs() << "[EduFlowCompiler] Modulo ya transferido al JIT.\n";
}

// ==========================================
// 3. FASE DE EJECUCIÓN JIT (HITO 2 y 3)
// ==========================================

// Estructura nativa en C++ que coincide con %Student de LLVM
struct StudentNative {
    int32_t credits_completed;
};

// Puntero a función compilada: bool f(StudentNative*)
using RuleFuncPtr = bool(*)(StudentNative*);

void EduFlowCompiler::executeJIT(const Program& program) {
    outs() << "\n--- INICIANDO MOTOR DE MATRICULA (HITO 3) ---\n";

    // 1. Inicialización del Hardware
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();

    // 2. Creación del JIT
    auto jitExpected = LLJITBuilder().create();
    if (!jitExpected) {
        errs() << "Error creando JIT: " << toString(jitExpected.takeError()) << "\n";
        return;
    }
    auto jit = std::move(*jitExpected);

    // 3. Transferencia del Módulo
    ThreadSafeModule tsm(std::move(module), std::move(context));
    if (auto err = jit->addIRModule(std::move(tsm))) {
        errs() << "Error añadiendo modulo: " << toString(std::move(err)) << "\n";
        return;
    }

    // 4. Bucle de Simulaciones (Lectura del AST)
    for (const auto& sim : program.simulations) {
        outs() << ">> Procesando Simulacion: " << sim->name << "\n";
        
        // Preparamos el estudiante nativo
        StudentNative nativeStudent;
        nativeStudent.credits_completed = sim->student->credits_completed;
        outs() << "   Estudiante ID: " << sim->student->id << ", Creditos Acumulados: " << nativeStudent.credits_completed << "\n";

        // Buscamos el Workflow asociado
        const WorkflowDef* wf = program.findWorkflow(sim->workflowId);
        if (!wf) {
            outs() << "   [ERROR CRITICO] Workflow '" << sim->workflowId << "' no encontrado. Abortando simulacion.\n";
            continue;
        }
        outs() << "   Usando Workflow: " << wf->id << "\n";

        // Estado local de la matrícula
        int totalCreditsEnrolled = 0;

        // Intentamos inscribir cada curso solicitado
        for (const auto& courseId : sim->coursesToEnroll) {
            outs() << "   -> Intentando inscribir en " << courseId << ": ";
            
            const CourseDef* course = program.findCourse(courseId);
            if (!course) {
                outs() << "ERROR (Curso no definido)\n";
                continue;
            }

            // --- VALIDACIÓN 1: Reglas Académicas (Hito 2 - JIT) ---
            bool rulePassed = true;
            if (!course->eligibilityRule.empty()) {
                // Buscamos la función compilada en memoria
                auto symExpected = jit->lookup(course->eligibilityRule);
                if (!symExpected) {
                    outs() << "ERROR INTERNO (Regla '" << course->eligibilityRule << "' no compilada)\n";
                    continue;
                }

                auto ruleFunc = (RuleFuncPtr)symExpected->getValue();
                // Ejecutamos la función generada por LLVM
                if (!ruleFunc(&nativeStudent)) {
                    outs() << "RECHAZADO (No cumple requisitos de regla: " << course->eligibilityRule << ")\n";
                    rulePassed = false;
                }
            }
            
            if (!rulePassed) continue; // Si falló la regla, pasamos al siguiente curso

            // --- VALIDACIÓN 2: Reglas de Workflow (Hito 3 - Lógica de Negocio) ---
            // Verificamos límites de créditos definidos en los Stages del Workflow
            
            // Simplificación: Tomamos el límite del primer stage o un default
            int stageMaxCredits = wf->stages.empty() ? 99 : wf->stages[0]->max_credits;

            if (totalCreditsEnrolled + course->credits > stageMaxCredits) {
                outs() << "RECHAZADO (Excede el limite de creditos del stage: " 
                       << stageMaxCredits << ". Actual: " << totalCreditsEnrolled 
                       << " + Curso: " << course->credits << ")\n";
                continue;
            }

            // Si pasa todo:
            totalCreditsEnrolled += course->credits;
            outs() << "APROBADO. (Total creditos inscritos: " << totalCreditsEnrolled << ")\n";
        }
        outs() << "---------------------------------------------------\n";
    }
}