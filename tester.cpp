#include "tester_solver.h"

#include <stdio.h>

#include "color_printf.h"
#include "my_assert.h"

static const char *filename = "tests.txt";

/// Start tests
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
