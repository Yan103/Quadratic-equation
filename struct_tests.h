/*!
    \file
    A file describing the structure of the test data
*/

#ifndef STRUCTER_TEST_H
#define STRUCTER_TEST_H

#include "number_roots.h"

/// Information about test (input) data
struct tests {
    double coeff_a;                 ///< Coefficient A
    double coeff_b;                 ///< Coefficient B
    double coeff_c;                 ///< Coefficient C
    number_roots exp_number_roots;  ///< Expected value of number_roots
    double exp_x1;                  ///< Expected values of x1
    double exp_x2;                  ///< Expected values of x2
};

#endif //STRUCTER_TEST_H
