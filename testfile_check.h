/*!
    \file
    A file with a description of the test data verification function
*/

#ifndef TESTFILE_CHECK_H
#define TESTFILE_CHECK_H

#include <stdio.h>

#include "number_roots.h"
#include "struct_tests.h"

/*!
    Function compares the expected (correct) data from the array of structures (test_ptr)
    and compares them with the values returned by the program, returns the number of passed tests
    \param [in] test_ptr - pointer on structure
    \return Returns the number of completed tests
*/
int testfile_check(tests *test_ptr, const int number_tests);

#endif //TESTFILE_CHECK_H
