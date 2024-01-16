# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(maths_exp_library VERSION 0.0.1 LANGUAGES C)

add_library(maths_exp SHARED
  "maths_exp.c"
        "error.c"
        "g77_interface.c"
        "matheval.c"
        "node.c"
        "symbol_table.c"
        "scanner.c"
        "xmalloc.c"
        "xmath.c"
        "scanner.l"
        "parser.y"
)

set_target_properties(maths_exp PROPERTIES
  PUBLIC_HEADER maths_exp.h
  PUBLIC_HEADER common.h
  PUBLIC_HEADER config.h
  PUBLIC_HEADER error.h
  PUBLIC_HEADER matheval.h
  PUBLIC_HEADER node.h
  PUBLIC_HEADER parser.h
  PUBLIC_HEADER symbol_table.h
  PUBLIC_HEADER xmalloc.h
  PUBLIC_HEADER xmath.h
  OUTPUT_NAME "maths_exp"
)

target_compile_definitions(maths_exp PUBLIC DART_SHARED_LIB)
