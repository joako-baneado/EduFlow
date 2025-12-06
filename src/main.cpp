#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "EduFlowLexer.h"
#include "EduFlowParser.h"
#include "EduFlowDriver.h"

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

    ANTLRInputStream input(stream);
    EduFlowLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    EduFlowParser parser(&tokens);
    EduFlowParser::ProgramContext* tree = parser.program();

    EduFlowDriver driver;
    driver.visitProgram(tree);

    std::cout << "\n--- LLVM IR Generado ---" << std::endl;
    driver.dumpIR();

    driver.executeSimulations();

    return 0;
}