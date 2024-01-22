#include <stdlib.h>
#include "maths_exp.h"
#include "gsl_math.h"
#include "gsl_diff.h"

double f (double x, void * params)
{
    (void)(params); /* avoid unused parameter warning */
    return pow (x, 10);
}

FFI_PLUGIN_EXPORT intptr_t sum(intptr_t a, intptr_t b) {
    gsl_function  F;
    double result, abserr;
    F.function = &f;
    F.params = 0;
    gsl_diff_central(&F, 6.0, &result, &abserr);
    return result; }

FFI_PLUGIN_EXPORT intptr_t sum_long_running(intptr_t a, intptr_t b) {
  // Simulate work.
#if _WIN32
  Sleep(5000);
#else
  usleep(5000 * 1000);
#endif
  return a+b;
}

