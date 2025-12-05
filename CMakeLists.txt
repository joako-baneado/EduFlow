cmake_minimum_required(VERSION 3.10)
project(EduFlow LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "LLVM found: ${LLVM_PACKAGE_VERSION}")
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

set(ANTLR_JAR "${CMAKE_CURRENT_SOURCE_DIR}/antlr-4.13.2-complete.jar")

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
    COMMENT "Generando archivos ANTLR C++ para EduFlow..."
)

find_path(ANTLR4_INCLUDE_DIR antlr4-runtime.h PATH_SUFFIXES antlr4-runtime)
find_library(ANTLR4_LIBRARY NAMES antlr4-runtime)

message(STATUS "ANTLR4 Header Dir: ${ANTLR4_INCLUDE_DIR}")
message(STATUS "ANTLR4 Library: ${ANTLR4_LIBRARY}")

if (NOT ANTLR4_INCLUDE_DIR OR NOT ANTLR4_LIBRARY)
    message(FATAL_ERROR "No se encontró ANTLR4 Runtime. \nVerifica instalación: sudo apt install libantlr4-runtime-dev")
endif()

add_executable(eduflow
    src/main.cpp
    ${ANTLR_GENERATED_SRC}
)

target_include_directories(eduflow PRIVATE
    src/
    ${CMAKE_CURRENT_BINARY_DIR}
    ${ANTLR4_INCLUDE_DIR}
)

llvm_map_components_to_libnames(LLVM_LIBS core support native targetparser executionengine orcjit)

target_link_libraries(eduflow PRIVATE
    ${LLVM_LIBS}
    ${ANTLR4_LIBRARY}
    pthread
    dl
)