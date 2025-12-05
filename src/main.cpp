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
    if (!stream.is_open()) return 1;

    ANTLRInputStream input(stream);
    EduFlowLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    EduFlowParser parser(&tokens);
    EduFlowParser::ProgramContext* tree = parser.program();

    ASTBuildVisitor visitor;
    visitor.visitProgram(tree);
    
    std::cout << "--- AST Construido ---" << std::endl;
    visitor.rootProgram->print();

    std::cout << "\n--- Generando LLVM IR ---" << std::endl;
    EduFlowCompiler compiler;
    compiler.compile(*visitor.rootProgram);
    compiler.dumpIR();

    // Pasamos el programa completo para leer las simulaciones
    compiler.executeJIT(*visitor.rootProgram);

    return 0;
}