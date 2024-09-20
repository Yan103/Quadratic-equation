/*!
    \file
    A file describing the structure of the equation
*/

#ifndef STRUCT_EQUATION_H
#define STRUCT_EQUATION_H

#include "number_roots.h"

/// Information about equation (coefficients, discriminant, roots and their number)
struct equation {
   double coeff_a;             ///< Coefficient A
   double coeff_b;             ///< Coefficient B
   double coeff_c;             ///< Coefficient C
   double D;                   ///< Discriminant
   double x1;                  ///< Root x1 (if there is one root, it is in x1)
   double x2;                  ///< Root x2 (x1 > x2)
   number_roots number_roots;  ///< Information about number of roots
};

#endif // STRUCT_EQUATION_H
