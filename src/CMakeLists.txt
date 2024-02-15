# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(maths_exp_library VERSION 0.0.1 LANGUAGES C)

set(SRC_DIR "matheval")
set(PARSER_DIR "${CMAKE_CURRENT_BINARY_DIR}")

find_package(FLEX 2.6 REQUIRED)
find_package(BISON 3.0 REQUIRED)

set(SCANNER_OUT "${SRC_DIR}/scanner.c")
set(PARSER_OUT "${SRC_DIR}/parser.c")

flex_target(SCANNER "${SRC_DIR}/scanner.l" "${SCANNER_OUT}" DEFINES_FILE "${SRC_DIR}/scanner.h")
bison_target(PARSER "${SRC_DIR}/parser.y" "${PARSER_OUT}" DEFINES_FILE "${SRC_DIR}/parser.h")

add_flex_bison_dependency(SCANNER PARSER)

add_library(maths_exp SHARED
        "maths_exp.c"
        "diff.c"
        "error.c"
        "message.c"
        "stream.c"
        "strerror.c"
        "matheval/error.c"
        "matheval/g77_interface.c"
        "matheval/matheval.c"
        "matheval/node.c"
        "matheval/symbol_table.c"
        "matheval/xmalloc.c"
        "matheval/xmath.c"
        )

set_target_properties(maths_exp PROPERTIES
        PUBLIC_HEADER maths_exp.h
        PUBLIC_HEADER gsl_math.h
        PUBLIC_HEADER gsl_inline.h
        PUBLIC_HEADER gsl_machine.h
        PUBLIC_HEADER gsl_pow_int.h
        PUBLIC_HEADER gsl_precision.h
        PUBLIC_HEADER gsl_nan.h
        PUBLIC_HEADER gsl_minmax.h
        PUBLIC_HEADER gsl_types.h
        PUBLIC_HEADER gsl_sys.h
        PUBLIC_HEADER templates_off.h
        PUBLIC_HEADER templates_on.h
        PUBLIC_HEADER gsl_diff.h
        PUBLIC_HEADER gsl_errno.h
        PUBLIC_HEADER gsl_message.h
        PUBLIC_HEADER matheval/common.h
        PUBLIC_HEADER matheval/config.h
        PUBLIC_HEADER matheval/error.h
        PUBLIC_HEADER matheval/matheval.h
        PUBLIC_HEADER matheval/node.h
        PUBLIC_HEADER matheval/symbol_table.h
        PUBLIC_HEADER matheval/xmalloc.h
        PUBLIC_HEADER matheval/xmath.h
        OUTPUT_NAME "maths_exp"
        )
target_compile_definitions(maths_exp PUBLIC DART_SHARED_LIB)
