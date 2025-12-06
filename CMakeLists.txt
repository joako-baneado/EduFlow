cmake_minimum_required(VERSION 3.10)
project(EduFlow LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. Configurar LLVM ---
find_package(LLVM REQUIRED CONFIG)
message(STATUS "LLVM found: ${LLVM_PACKAGE_VERSION}")
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# CRÍTICO: Decirle al linker dónde está libLLVM.so
link_directories(${LLVM_LIBRARY_DIRS})

# --- 2. Configurar ANTLR ---
set(ANTLR_JAR "${CMAKE_CURRENT_SOURCE_DIR}/antlr-4.13.2-complete.jar")
set(ANTLR_URL "https://www.antlr.org/download/antlr-4.13.2-complete.jar")

if(NOT EXISTS "${ANTLR_JAR}")
    file(DOWNLOAD "${ANTLR_URL}" "${ANTLR_JAR}" SHOW_PROGRESS STATUS download_status)
    list(GET download_status 0 status_code)
    if(NOT status_code EQUAL 0)
        file(REMOVE "${ANTLR_JAR}")
        message(FATAL_ERROR "Error downloading ANTLR")
    endif()
endif()

find_package(Java REQUIRED)

set(ANTLR_GENERATED_SRC
    ${CMAKE_CURRENT_BINARY_DIR}/EduFlowLexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/EduFlowLexer.h
    ${CMAKE_CURRENT_BINARY_DIR}/EduFlowParser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/EduFlowParser.h
    ${CMAKE_CURRENT_BINARY_DIR}/EduFlowBaseVisitor.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/EduFlowBaseVisitor.h
    ${CMAKE_CURRENT_BINARY_DIR}/EduFlowVisitor.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/EduFlowVisitor.h
)

add_custom_command(
    OUTPUT ${ANTLR_GENERATED_SRC}
    COMMAND ${Java_JAVA_EXECUTABLE} -jar ${ANTLR_JAR} -Dlanguage=Cpp -visitor -no-listener -package antlr4 -o ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/EduFlow.g4
    DEPENDS src/EduFlow.g4 ${ANTLR_JAR}
)

find_path(ANTLR4_INCLUDE_DIR antlr4-runtime.h PATH_SUFFIXES antlr4-runtime)
find_library(ANTLR4_LIBRARY NAMES antlr4-runtime)

if (NOT ANTLR4_INCLUDE_DIR OR NOT ANTLR4_LIBRARY)
    message(FATAL_ERROR "ANTLR4 Runtime not found")
endif()

# --- 3. Ejecutable ---
add_executable(eduflow
    src/main.cpp
    src/visitor/ASTBuildVisitor.cpp
    src/codegen/EduFlowCompiler.cpp
    ${ANTLR_GENERATED_SRC}
)

target_include_directories(eduflow PRIVATE
    src/
    src/ast
    src/visitor
    src/codegen
    ${CMAKE_CURRENT_BINARY_DIR}
    ${ANTLR4_INCLUDE_DIR}
)

# --- 4. Enlazado (La parte crítica) ---
target_link_libraries(eduflow PRIVATE
    LLVM              # <--- Intentamos enlazar la librería monolítica
    ${ANTLR4_LIBRARY}
    pthread
    dl
)