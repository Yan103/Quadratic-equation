/*!
    \file
    A file with a description of the codes containing information about the number of roots of the equation
*/

#ifndef NUMBER_ROOTS_H
#define NUMBER_ROOTS_H

/// Information about equation (coefficients, discriminant, roots and their number)
enum number_roots {
    INF_ROOTS = -1,   //< Equation has infinitely many roots
    UNKNOWN   = -2,   //< Default parameter (for error detection)
    NO_ROOTS  =  0,   //< Equation has no roots
    ONE_ROOT  =  1,   //< Equation has 1 root
    TWO_ROOTS =  2,   //< Equation has 2 roots
};

#endif // NUMBER_ROOTS_H
