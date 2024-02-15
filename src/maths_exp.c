#include <stdlib.h>
#include "maths_exp.h"
#include "gsl_math.h"
#include "gsl_diff.h"
#include "matheval.h"
#include <stdio.h>
#include <string.h>

FFI_PLUGIN_EXPORT intptr_t sum(intptr_t a, intptr_t b) {


    return (a+b);
}

FFI_PLUGIN_EXPORT intptr_t sum_long_running(intptr_t a, intptr_t b) {
  // Simulate work.
#if _WIN32
  Sleep(5000);
#else
  usleep(5000 * 1000);
#endif
  return a+b;
}

