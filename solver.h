/*!
    \file
    A file with a description of the functions for solving the equation
*/

#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>

#include "struct_equation.h"

/*!
    The function solve_equation solves a quadratic equation (or linear if the coefficient a = 0)
    and writes the roots/root into the appropriate structure, information about the number of roots is also recorded
    \param [out] equation_ptr - equation pointer
*/
void solve_equation(equation *equation_ptr);

/*!
    Function compares the entered number with 0 (returns true if the number is zero, otherwise false)
    \param [in] number - the number to be compared with 0
*/
bool IS_ZERO(double number);

#endif // SOLVER_H
