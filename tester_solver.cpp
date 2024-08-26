#include "tester_solver.h"

#include <stdio.h>

#include "color_printf.h"
#include "my_assert.h"
#include "return_codes.h"

/// Start tests
int tester_solver(const char *tests_filename) {

    FILE *test_file = fopen(tests_filename, "r");

    if (!test_file) {
        printf(RED("Error occured while opening file\n"));

        return FILE_ERROR;
    }

    int number_tests = 0;
    fscanf(test_file, "%d", &number_tests);

    tests *test_arr = (tests*) calloc(number_tests, sizeof(tests));

    if (test_arr == NULL) return MEMORY_ERROR;

    testfile_read(test_file, test_arr);

    int count = testfile_check(test_arr, number_tests);

    free(test_arr);
    fclose(test_file);

    if (count == number_tests) {
        printf(GREEN("END OF TEST! Successfully %d/%d\n"), count, number_tests);
    } else {
        printf(RED("END OF TEST! Successfully %d/%d\n"), count, number_tests);
    }
    
    return SUCCESS;
}
