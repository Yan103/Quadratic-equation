/*!
    \file
    A file describing the function of testing the algorithm for solving the equation
*/

#include "test_system.h"

#include <math.h>
#include <stdio.h>

#include "my_assert.h"

static const double EPS = 1e-5; /// A small value to compare numbers of the type

/*!
    The function compares two numbers
    \param [in]  first - first number
    \param [in] second - second number
    \return Returns 1 if the numbers are equal, otherwise 0
*/
static bool is_equal(double first, double second) {
    return fabs(first - second) < EPS;
}

/*!
    Function receives the coefficients of the equation and the expected (correct)
     values as input, if they do not match, it outputs the relevant information
    \param [in]      test_number - number of test
    \param [in]          coeff_a - coefficient A
    \param [in]          coeff_b - coefficient B
    \param [in]          coeff_c - coefficient C
    \param [in] exp_number_roots - expected value number_roots
    \param [in]           exp_x1 - expected value x1
    \param [in]           exp_x2 - expected value x2
    \return Returns the count of completed tests
*/
int test_system(int test_number, double coeff_a, double coeff_b, double coeff_c,
               number_roots exp_number_roots, double exp_x1, double exp_x2)
    {
    int count = 0;
    struct equation quadratic_equation = {.coeff_a = coeff_a,
                                          .coeff_b = coeff_b,
                                          .coeff_c = coeff_c,
                                          .D = coeff_b * coeff_b - 4 * coeff_a * coeff_c,
                                          .x1 = UNKNOWN,
                                          .x2 = UNKNOWN,
                                          .number_roots = UNKNOWN};

    solve_equation(&quadratic_equation);

    if (exp_number_roots == NO_ROOTS && quadratic_equation.number_roots == NO_ROOTS) {
        count++;
    } else {
        if (exp_number_roots != quadratic_equation.number_roots
            || !is_equal(exp_x1, quadratic_equation.x1)
            || !is_equal(exp_x2, quadratic_equation.x2))
        {
            printf(RED("Error: Test %d\n"
                   "Get: x1=%lg x2=%lg nRoot=%d\n)"
                   "Expected: x1=%lg x2=%lg nRoot=%d\n"), test_number,
                   quadratic_equation.x1, quadratic_equation.x2,
                   quadratic_equation.number_roots,
                   exp_x1, exp_x2, exp_number_roots);
        } else {
            count++;
        }
    }

    return count;
}
