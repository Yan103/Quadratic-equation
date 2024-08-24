#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>

#include "struct_equation.h"

//-----------------------------------------------------
///< @param [out] e_ptr - equation pointer
///<
///< @note The function solve_equation solves a quadratic equation (or linear if the coefficient a = 0)
///<       and writes the roots/root into the appropriate structure, information about the number of roots is also recorded
void solve_equation(equation *equation_ptr);

//-----------------------------------------------------
///< @param [in] x - the number to be compared with 0
///<
///< @note Function compares the entered number with 0 (returns true if the number is zero, otherwise false)
bool IS_ZERO(double x);

#endif // SOLVER_H
