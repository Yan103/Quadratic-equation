#ifndef STRUCT_EQUATION_H
#define STRUCT_EQUATION_H

#include "nRoots.h"

//-----------------------------------------------------
///< @note Information about equation (coefficients, discriminant, roots and their number)
struct equation {
   double coeff_a, coeff_b, coeff_c;   //< Coefficients
   double D;         //< Discriminant
   double x1, x2;    //< Roots x1 < x2 (if there is one root, it is in x1) */
   nRoots nRoots;    //< Information about number of roots */
};

#endif // STRUCT_EQUATION_H
