/*!
    \file
    File with the declaration of the my_assert function
*/

#ifndef TESTER_SOLVER_H
#define TESTER_SOLVER_H

#include <stdio.h>

#include "structer_tests.h"
#include "testfile_check.h"
#include "testfile_read.h"
#include "testsystem.h"

/*!
    Function reads the test data from file and checks the correctness of
    the equation solution function, result if output to the console
*/
int tester_solver(const char *tests_filename);

#endif // TESTER_SOLVER_H
