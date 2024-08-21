#include <stdio.h>

#include "testfile_check.h"
#include "testfile_read.h"
#include "testsystem.h"
#include "structer_tests.h"


const int N_TESTS = 25; // Number of tests

void tester_solver();

void tester_solver() {
    const char *filename = "tests.txt";
    tests test_arr[N_TESTS] = {};

    testfile_read(filename, test_arr);

    int count = testfile_check(test_arr);

    printf("END OF TEST! Successfully %d/%d\n", count, N_TESTS);
}
