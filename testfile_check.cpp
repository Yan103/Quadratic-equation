#include <stdio.h>

#include "nRoots.h"
#include "my_assert.h"
#include "structer_tests.h"
#include "testsystem.h"

const int N_TESTS = 25; // Number of tests

//
int testfile_check(tests *test_ptr);

int testfile_check(tests *test_ptr) {
    my_assert(test_ptr != nullptr , "Null pointer was passed\n");

    int count = 0;
    for (int j = 0; j < N_TESTS; j++) {
        count += TestSystem(j + 1, test_ptr[j].a, test_ptr[j].b, test_ptr[j].c, test_ptr[j].exp_nRoots, test_ptr[j].exp_x1, test_ptr[j].exp_x2);
    }
    
    return count;
}
