/*!
    \file
    The file describing the function of reading test data from a file
*/

#ifndef TESTFILE_READ_H
#define TESTFILE_READ_H

#include <stdio.h>

#include "number_roots.h"
#include "struct_tests.h"

/*!
    Function reads data from a file intended for testing the program and writes it to an array of structures (test_ptr)
    \param [in]  filename - name of file with tests
    \param [out] test_ptr - pointer on structure
    \return Returns the status of the process of reading test data from a file
*/
int testfile_read(FILE *filename, tests *test_ptr);

#endif // TESTFILE_READ_H
