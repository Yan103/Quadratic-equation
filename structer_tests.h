/*!
    \file
    A file describing the structure of the test data
*/

#ifndef STRUCTER_TEST_H
#define STRUCTER_TEST_H

#include "nRoots.h"

/// Information about test (input) data
struct tests {
    double coeff_a, coeff_b, coeff_c;       //< Coefficients
    nRoots exp_nRoots;                      //< Expected value of nRoots
    double exp_x1, exp_x2;                  //< Expected values of x1 and x2
};

/// Number of tests
const int N_TESTS = 25;

#endif //STRUCTER_TEST_H
