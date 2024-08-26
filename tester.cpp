#include "tester_solver.h"

#include <stdio.h>

#include "color_printf.h"
#include "my_assert.h"
#include "return_codes.h"

/// static const char *TESTS_FILENAME = "tests.txt";

/// Start tests
int tester_solver(const char *tests_filename) { // todo filename as param

    FILE *testfile = fopen(tests_filename, "r");

    if (!testfile) {
        printfRed("Error occured while opening file\n");

        return FILE_ERROR; // todo \n VEZDEEEEEEEEEE
    }

    int number_tests = 0; // todo no ptr
    fscanf(testfile, "%d", &number_tests);

    tests *test_arr = (tests*) calloc(number_tests, sizeof(tests));

    if (test_arr == NULL) return MEMORY_ERROR;

    /// tests test_arr[N_TESTS] = {};

    testfile_read(testfile, test_arr);

    int count = testfile_check(test_arr, number_tests);

    free(test_arr);
    fclose(testfile);

    if (count == number_tests) printfGreen("END OF TEST! Successfully %d/%d\n", count, number_tests);
    else printfRed("END OF TEST! Successfully %d/%d\n", count, number_tests);

    return SUCCESS;
}
