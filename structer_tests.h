#ifndef STRUCTER_TEST_H
#define STRUCTER_TEST_H

#include "nRoots.h"

//-----------------------------------------------------
///< @note Information about test (input) data
struct tests {
    double coeff_a, coeff_b, coeff_c;          //< Coefficients
    nRoots exp_nRoots;       //< Expected value of nRoots
    double exp_x1, exp_x2;   //< Expected values of x1 and x2
};

const int N_TESTS = 25; // Number of tests

#endif //STRUCTER_TEST_H
