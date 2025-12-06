cmake_minimum_required(VERSION 3.10)
# CORRECCIÓN: Habilitamos C y CXX para que LLVM pueda hacer sus chequeos internos de dependencias
project(EduFlow LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. Configurar LLVM ---
find_package(LLVM REQUIRED CONFIG)
message(STATUS "LLVM found: ${LLVM_PACKAGE_VERSION}")
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# --- 2. Configurar ANTLR (Generador Java) ---
# Definimos la URL y el archivo destino
set(ANTLR_JAR "${CMAKE_CURRENT_SOURCE_DIR}/antlr-4.13.2-complete.jar")
set(ANTLR_URL "https://www.antlr.org/download/antlr-4.13.2-complete.jar")

# Si no existe, lo descargamos
if(NOT EXISTS "${ANTLR_JAR}")
    message(STATUS "Descargando ANTLR JAR desde ${ANTLR_URL}...")
    file(DOWNLOAD "${ANTLR_URL}" "${ANTLR_JAR}"
        SHOW_PROGRESS
        STATUS download_status
    )
    list(GET download_status 0 status_code)
    list(GET download_status 1 status_string)

    if(NOT status_code EQUAL 0)
        file(REMOVE "${ANTLR_JAR}") # Limpiamos si falló
        message(FATAL_ERROR "Error al descargar ANTLR: ${status_string}")
    endif()
    message(STATUS "ANTLR JAR descargado correctamente.")
endif()

find_package(Java REQUIRED)

# Definimos los archivos que esperamos que ANTLR genere
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

# Comando para ejecutar el JAR y generar el código C++ desde la gramática
add_custom_command(
    OUTPUT ${ANTLR_GENERATED_SRC}
    COMMAND ${Java_JAVA_EXECUTABLE} -jar ${ANTLR_JAR} -Dlanguage=Cpp -visitor -no-listener -package antlr4 -o ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/EduFlow.g4
    DEPENDS src/EduFlow.g4 ${ANTLR_JAR}
    COMMENT "Generando archivos ANTLR C++ para EduFlow..."
)

# --- 3. Configurar Runtime de ANTLR (Librería C++) ---
# Buscamos la ruta del header (.h)
find_path(ANTLR4_INCLUDE_DIR antlr4-runtime.h PATH_SUFFIXES antlr4-runtime)
# Buscamos la librería compilada (.so / .a)
find_library(ANTLR4_LIBRARY NAMES antlr4-runtime)

# Mensajes de depuración
message(STATUS "ANTLR4 Header Dir: ${ANTLR4_INCLUDE_DIR}")
message(STATUS "ANTLR4 Library: ${ANTLR4_LIBRARY}")

if (NOT ANTLR4_INCLUDE_DIR OR NOT ANTLR4_LIBRARY)
    message(FATAL_ERROR "No se encontró ANTLR4 Runtime. \nVerifica instalación: sudo apt install libantlr4-runtime-dev")
endif()

# --- 4. Definir el Ejecutable ---
add_executable(eduflow
    src/main.cpp
    src/visitor/ASTBuildVisitor.cpp
    src/codegen/EduFlowCompiler.cpp
    ${ANTLR_GENERATED_SRC} # Incluimos los fuentes generados
)

# --- 5. Configurar Includes y Links ---
target_include_directories(eduflow PRIVATE
    src/
    src/ast
    src/visitor
    src/codegen
    ${CMAKE_CURRENT_BINARY_DIR} # Importante: Aquí están los .h generados (Lexer.h, Parser.h)
    ${ANTLR4_INCLUDE_DIR}       # Aquí está el runtime de ANTLR instalado en el sistema
)

# Mapeamos los componentes de LLVM necesarios (Agregué OrcJIT y ExecutionEngine para tu proyecto)
llvm_map_components_to_libnames(LLVM_LIBS core support native targetparser executionengine orcjit)

target_link_libraries(eduflow PRIVATE
    ${LLVM_LIBS}
    ${ANTLR4_LIBRARY}
    pthread
    dl
)