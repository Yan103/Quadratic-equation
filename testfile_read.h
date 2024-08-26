/*!
    \file
    File with the declaration of the my_assert function
*/

#ifndef TESTFILE_READ_H
#define TESTFILE_READ_H

#include <stdio.h>

#include "nRoots.h"
#include "structer_tests.h"

/*!
    Function reads data from a file intended for testing the program and writes it to an array of structures (test_ptr)
    \param [in]  filename - name of file with tests
    \param [out] test_ptr - pointer on structure
*/
int testfile_read(FILE *filename, tests *test_ptr);

#endif // TESTFILE_READ_H
