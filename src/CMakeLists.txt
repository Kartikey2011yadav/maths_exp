# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(maths_exp_library VERSION 0.0.1 LANGUAGES C)

add_library(maths_exp SHARED
  "maths_exp.c"
)

set_target_properties(maths_exp PROPERTIES
  PUBLIC_HEADER maths_exp.h
  PUBLIC_HEADER gsl_math.h
  OUTPUT_NAME "maths_exp"
)

target_compile_definitions(maths_exp PUBLIC DART_SHARED_LIB)
