# Buscamos el Path de los Headers
find_path(ANTLR4_INCLUDE_DIR
    NAMES antlr4-runtime.h
    PATH_SUFFIXES antlr4-runtime
    PATHS
    /usr/include
    /usr/local/include
    /opt/local/include
)

# Buscamos la Librería (.so / .a)
find_library(ANTLR4_LIBRARY
    NAMES antlr4-runtime
    PATHS
    /usr/lib
    /usr/local/lib
    /opt/local/lib
    /usr/lib/x86_64-linux-gnu
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ANTLR4
    DEFAULT_MSG
    ANTLR4_LIBRARY ANTLR4_INCLUDE_DIR
)

if(ANTLR4_FOUND)
    set(ANTLR4_LIBRARIES ${ANTLR4_LIBRARY})
    set(ANTLR4_INCLUDE_DIRS ${ANTLR4_INCLUDE_DIR})
    
    # Crear un target importado para uso moderno en CMake
    if(NOT TARGET ANTLR4::antlr4-runtime)
        add_library(ANTLR4::antlr4-runtime UNKNOWN IMPORTED)
        set_target_properties(ANTLR4::antlr4-runtime PROPERTIES
            IMPORTED_LOCATION "${ANTLR4_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${ANTLR4_INCLUDE_DIR}"
        )
    endif()
endif()

mark_as_advanced(ANTLR4_INCLUDE_DIR ANTLR4_LIBRARY)