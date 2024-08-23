#ifndef TESTSYSTEM_H
#define TESTSYSTEM_H

#include "nRoots.h"
#include "solver.h"
#include "struct_equation.h"

//-----------------------------------------------------
///< @param [in] test_number - number of test
///< @param [in]           a - coefficient A
///< @param [in]           b - coefficient B
///< @param [in]           c - coefficient C
///< @param [in]  exp_nRoots - expected value nRoots
///< @param [in]      exp_x1 - expected value x1
///< @param [in]      exp_x2 - expected value x2
///<
///< @note  Function receives the coefficients of the equation and the expected (correct) values as input, if they do not match, it outputs the relevant information
int TestSystem(int test_number, double a, double b, double c, nRoots exp_nRoots, double exp_x1, double exp_x2);

//-----------------------------------------------------
///< @param [in] x - first number
///< @param [in] y - second number
///<
///< @note Function compares 2 entered numbers
bool IS_EQUAL(double x, double y);

#endif // TESTSYSTEM_H
