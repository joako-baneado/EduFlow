#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "EduFlowLexer.h"
#include "EduFlowParser.h"
#include "visitor/ASTBuildVisitor.h"
#include "codegen/EduFlowCompiler.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: ./eduflow <archivo_entrada.in>" << std::endl;
        return 1;
    }

    std::ifstream stream;
    stream.open(argv[1]);
    if (!stream.is_open()) {
        std::cerr << "Error abriendo archivo: " << argv[1] << std::endl;
        return 1;
    }

    std::cout << "--- 1. Parsing ---" << std::endl;
    ANTLRInputStream input(stream);
    EduFlowLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    EduFlowParser parser(&tokens);
    EduFlowParser::ProgramContext* tree = parser.program();

    std::cout << "--- 2. AST Construction ---" << std::endl;
    ASTBuildVisitor visitor;
    visitor.visitProgram(tree);
    
    // Verificamos si se construyó algo
    if (visitor.rootProgram->courses.empty() && 
        visitor.rootProgram->rules.empty() && 
        visitor.rootProgram->workflows.empty() && 
        visitor.rootProgram->simulations.empty()) {
        std::cerr << "Advertencia: El AST parece vacio." << std::endl;
    } else {
        visitor.rootProgram->print();
    }

    std::cout << "\n--- 3. LLVM Compilation & Optimization ---" << std::endl;
    EduFlowCompiler compiler;
    compiler.compile(*visitor.rootProgram);
    
    std::cout << "\n[DEBUG] LLVM IR (Pre-Optimization) " << std::endl;
    compiler.dumpIR(); // Ver IR sucio

    // AQUÍ OCURRE LA MAGIA DE LA OPTIMIZACIÓN
    compiler.optimize(); 

    std::cout << "\n--- 4. LLVM IR Dump (Optimized) ---" << std::endl;
    compiler.dumpIR();

    std::cout << "\n--- 5. JIT Execution (Hito 3) ---" << std::endl;
    compiler.executeJIT(*visitor.rootProgram);

    return 0;
}