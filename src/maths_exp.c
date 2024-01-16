#include "maths_exp.h"
#include "matheval.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//#define BUFFER_SIZE 256
// A very short-lived native function.
//
// For very short-lived functions, it is fine to call them on the main isolate.
// They will block the Dart execution while running the native function, so
// only do this for native functions which are guaranteed to be short-lived.
FFI_PLUGIN_EXPORT intptr_t sum(intptr_t a, intptr_t b) {

    void *f, *f_prim;		/* Evaluators for function and function derivative.  */
    char **names;			/* Function variables names. */
    int count;			/* Number of function variables. */
    double x;			/* Variable x value.  */
    int i;			/* Loop counter. */
    f = evaluator_create ("x");
//    assert (f);
//    evaluator_get_variables (f, &names, &count);
//    f_prim = evaluator_derivative_x (f);
//    x=4.50;
//    int t = evaluator_evaluate_x (f_prim, x);
//    evaluator_destroy (f);
//    evaluator_destroy (f_prim);
    return a+b; }

// A longer-lived native function, which occupies the thread calling it.
//
// Do not call these kind of native functions in the main isolate. They will
// block Dart execution. This will cause dropped frames in Flutter applications.
// Instead, call these native functions on a separate isolate.
FFI_PLUGIN_EXPORT intptr_t sum_long_running(intptr_t a, intptr_t b) {
  // Simulate work.
#if _WIN32
  Sleep(5000);
#else
  usleep(5000 * 1000);
#endif
  return a+b;
}

