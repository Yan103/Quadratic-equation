#ifndef STRUCTER_TEST_H
#define STRUCTER_TEST_H

#include "nRoots.h"

//-----------------------------------------------------
//! @note Information about test (input) data
struct tests {
    double a, b, c;          //< Coefficients
    nRoots exp_nRoots;       //< Expected value of nRoots
    double exp_x1, exp_x2;   //< Expected values of x1 and x2
};

#endif //STRUCTER_TEST_H
