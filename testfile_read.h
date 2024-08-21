#ifndef TESTFILE_READ_H
#define TESTFILE_READ_H

#include <stdio.h>

#include "nRoots.h"
#include "structer_tests.h"

//-----------------------------------------------------
//! @param [in] filename - name of file with tests
//! @param [out] test_ptr - pointer on structure
//!
//! @note Function reads data from a file intended for testing the program and writes it to an array of structures (test_ptr)
int testfile_read(const char *filename, tests *test_ptr);

#endif // TESTFILE_READ_H
