/*!
    \file
    A file describing the function of testing the algorithm for solving the equation
*/

#ifndef TESTSYSTEM_H
#define TESTSYSTEM_H

#include "number_roots.h"
#include "solver.h"
#include "struct_equation.h"

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
               number_roots exp_number_roots, double exp_x1, double exp_x2);

#endif // TESTSYSTEM_H
