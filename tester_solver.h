/*!
    \file
    A file with a description of the function that starts checking the algorithm for solving the equation
*/

#ifndef TESTER_SOLVER_H
#define TESTER_SOLVER_H

#include <stdio.h>
#include <stdlib.h>

#include "struct_tests.h"
#include "testfile_check.h"
#include "testfile_read.h"
#include "test_system.h"

/*!
    Function reads the test data from file and checks the correctness of
    the equation solution function, result if output to the console
    \param [in] tests_filename - the name of the file containing the test data
    \return Returns the verification status of the algorithm for solving the equation
*/
int tester_solver(const char *tests_filename);

#endif // TESTER_SOLVER_H
