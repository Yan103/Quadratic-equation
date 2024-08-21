#ifndef TESTFILE_CHECK_H
#define TESTFILE_CHECK_H

#include <stdio.h>

#include "nRoots.h"
#include "structer_tests.h"
#include "testsystem.h"

//-----------------------------------------------------
//! @param [in] test_ptr - pointer on structure
//!
//! @note  Function compares the expected (correct) data from the array of structures (test_ptr)
//!        and compares them with the values returned by the program, returns the number of passed tests
int testfile_check(tests *test_ptr);

#endif //TESTFILE_CHECK_H
