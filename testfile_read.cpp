#include "testfile_read.h"

#include "color_printf.h"
#include "my_assert.h"
#include "return_codes.h"

/// Reading expected data from a file
int testfile_read(const char *filename, tests *test_ptr) {
    ASSERT(test_ptr != nullptr, "Null pointer was passed");
    ASSERT(filename != nullptr, "Null pointer was passed");

    double coeff_a = 0, coeff_b = 0, coeff_c = 0, exp_x1 = 0, exp_x2 = 0;
    int fnRoots = 0;

    FILE *testfile = fopen(filename, "r");

    if (!testfile) {
        printfRed("Error occured while opening file\n");
        return FILE_ERROR;
    }

    int i = 0;
    while((fscanf(testfile, "%lf %lf %lf %d %lf %lf\n",
           &coeff_a, &coeff_b, &coeff_c, &fnRoots, &exp_x1, &exp_x2)) != EOF)
    {
        test_ptr[i] = {.coeff_a = coeff_a,
                       .coeff_b = coeff_b,
                       .coeff_c = coeff_c,
                       .exp_nRoots = (nRoots)fnRoots,
                       .exp_x1 = exp_x1,
                       .exp_x2 = exp_x2};
        i++;
    }
    fclose(testfile);

    return SUCCESS;
}
