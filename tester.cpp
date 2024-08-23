#include <assert.h>
#include <stdio.h>

#include "color_printf.h"
#include "my_assert.h"
#include "structer_tests.h"
#include "testfile_check.h"
#include "testfile_read.h"
#include "testsystem.h"

static const char *filename = "tests.txt";

void tester_solver();

void tester_solver() {

    tests test_arr[N_TESTS] = {};

    testfile_read(filename, test_arr);

    int count = testfile_check(test_arr);

    if (count == N_TESTS) {
        printfGreen("END OF TEST! Successfully %d/%d\n", count, N_TESTS);
    } else {
        printfRed("END OF TEST! Successfully %d/%d\n", count, N_TESTS);
    }
}
