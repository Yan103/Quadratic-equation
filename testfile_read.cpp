/*!
    \file
    The file describing the function of reading test data from a file
*/

#include "testfile_read.h"

#include "color_printf.h"
#include "my_assert.h"
#include "return_codes.h"

/*!
    Function reads data from a file intended for testing the program and writes it to an array of structures (test_ptr)
    \param [in]  filename - name of file with tests
    \param [out] test_ptr - pointer on structure
    \return Returns the status of the process of reading test data from a file
*/
int testfile_read(FILE *file_name, tests *test_ptr) {
    ASSERT(test_ptr != nullptr, "Null pointer was passed");
    ASSERT(file_name != nullptr, "Null pointer was passed");

    double coeff_a = 0, coeff_b = 0, coeff_c = 0;
    double exp_x1 = 0, exp_x2 = 0;
    int fn_roots = 0;

    int i = 0;
    while((fscanf(file_name, "%lf %lf %lf %d %lf %lf\n",
                  &coeff_a, &coeff_b, &coeff_c,
                  &fn_roots, &exp_x1, &exp_x2)) != EOF)
    {
        test_ptr[i] = {.coeff_a = coeff_a,
                       .coeff_b = coeff_b,
                       .coeff_c = coeff_c,
                       .exp_number_roots = (number_roots)fn_roots,
                       .exp_x1 = exp_x1,
                       .exp_x2 = exp_x2};
        i++;
    }

    return SUCCESS;
}
