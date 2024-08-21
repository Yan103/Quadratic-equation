#include <stdio.h>

#include "nRoots.h"
#include "structer_tests.h"
#include "testsystem.h"

const int N_TESTS = 25; // Number of tests

//
int testfile_check(tests *test_ptr);

int testfile_check(tests *test_ptr) {
    int count = 0;
    for (int j = 0; j < N_TESTS; j++) {
        count += TestSystem(j + 1, test_ptr[j].a, test_ptr[j].b, test_ptr[j].c, test_ptr[j].nRoots, test_ptr[j].exp_x1, test_ptr[j].exp_x2);
    }

    return count;
}
