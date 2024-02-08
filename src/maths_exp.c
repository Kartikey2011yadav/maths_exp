#include <stdlib.h>
#include "maths_exp.h"
#include "gsl_math.h"
#include "gsl_diff.h"
#include "matheval.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define BUFFER_SIZE 256;

double f (double x, void * params)
{
    (void)(params); /* avoid unused parameter warning */
    return pow (x, 10);
}

FFI_PLUGIN_EXPORT intptr_t sum(intptr_t a, intptr_t b) {
//    gsl_function  F;
//    double result, abserr;
//    F.function = &f;
//    F.params = 0;
//    gsl_diff_central(&F, 6.0, &result, &abserr);
//
//    void *f, *f_prim;		/* Evaluators for function and function derivative.  */
//    char **names;			/* Function variables names. */
//    int count;			/* Number of function variables. */
//    double x;
//
//    /* Create evaluator for function.  */
//    f = evaluator_create ("x^4");
//    assert (f);
//    /* Print variable names appearing in function. */
//    evaluator_get_variables (f, &names, &count);
//    f_prim = evaluator_derivative_x (f);
//    int val = evaluator_evaluate_x (f_prim, x);
//    evaluator_destroy (f);
//    evaluator_destroy (f_prim);
//    return val;

    char buffer[]= "x^3\0";;	/* Input buffer.  */
    int length;			/* Length of above buffer. */
    void *f, *f_prim;		/* Evaluators for function and function derivative.  */
    char **names;			/* Function variables names. */
    int count;			/* Number of function variables. */
    double x;			/* Variable x value.  */
    int i;			/* Loop counter. */

    /* Read function.  Function has to be over variable x, or result may
       be undetermined.  Size of textual represenatation of function is
       bounded here to 256 characters, in real conditions one should
       probably use GNU readline() instead of fgets() to overcome this
       limit.  */
//   buffer = "x^3";


    /* Create evaluator for function.  */
    f = evaluator_create ("x^3");
    assert (f);

    /* Print variable names appearing in function. */
    evaluator_get_variables (f, &names, &count);


    /* Create evaluator for function derivative and print textual
       representation of derivative.  */
    f_prim = evaluator_derivative_x (f);
    printf ("  f'(x) = %s\n", evaluator_get_string (f_prim));

    /* Read variable x value.  */
//    printf ("x = ");
//    scanf ("%lf", &x);
//    x= 6;
//
//    /* Calculate and print values of function and its derivative for given
//       value of x.  */
//    printf ("  f(%g) = %g\n", x, evaluator_evaluate_x (f, x));
//    printf ("  f'(%g) = %g\n", x, evaluator_evaluate_x (f_prim, x));

//    /* Destroy evaluators.  */
//    evaluator_destroy (f);
//    evaluator_destroy (f_prim);
//    return evaluator_evaluate_x (f_prim, x);
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

