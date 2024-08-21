#ifndef STRUCT_EQUATION_H
#define STRUCT_EQUATION_H

#include "roots_status.h"

// Information about equation (coefficients, discriminant, roots and their number)
struct equation {
   double a, b, c;         /* Coefficients */
   double D;               /* Discriminant */
   double x1, x2;          /* Roots x1 < x2 (if there is one root, it is in x1) */
   RootsStatus nRoots;     /* Information about number of roots */
};

#endif // STRUCT_EQUATION_H
