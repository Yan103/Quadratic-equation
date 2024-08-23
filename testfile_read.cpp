#include <stdio.h>

#include "color_printf.h"
#include "my_assert.h"
#include "nRoots.h"
#include "return_codes.h"
#include "structer_tests.h"

const int N_TESTS = 25; // Number of tests

int testfile_read(const char *filename, tests *test_ptr);

//
int testfile_read(const char *filename, tests *test_ptr) {
    my_assert(test_ptr != nullptr , "Null pointer was passed\n");
    my_assert(filename != nullptr , "Null pointer was passed\n");

    double a = 0, b = 0, c = 0, exp_x1 = 0, exp_x2 = 0;
    int fnRoots = 0;

    FILE *testfile = fopen(filename, "r");

    if (!testfile) {
        printfRed("Error occured while opening file\n");
        return FILE_ERROR;
    }

    int i = 0;
    while((fscanf(testfile, "%lf %lf %lf %d %lf %lf\n", &a, &b, &c, &fnRoots, &exp_x1, &exp_x2)) != EOF) {
        test_ptr[i++] = {a, b, c, (nRoots)fnRoots, exp_x1, exp_x2};
    }
    fclose(testfile);

    return SUCCESS;
}
