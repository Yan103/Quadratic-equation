/*!
    \file
    A file with a description of the test data verification function
*/

#include "testfile_check.h"

#include "my_assert.h"
#include "test_system.h"

/*!
    Function compares the expected (correct) data from the array of structures (test_ptr)
    and compares them with the values returned by the program, returns the number of passed tests
    \param [in] test_ptr - pointer on structure
    \return Returns the number of completed tests
*/
int testfile_check(tests *test_ptr, const int number_tests) {
    ASSERT(test_ptr != nullptr, "Null pointer was passed");

    int count = 0;
    for (int test_index = 0; test_index < number_tests; test_index++)
    {
        count += test_system(test_index + 1,
                            test_ptr[test_index].coeff_a,
                            test_ptr[test_index].coeff_b,
                            test_ptr[test_index].coeff_c,
                            test_ptr[test_index].exp_number_roots,
                            test_ptr[test_index].exp_x1,
                            test_ptr[test_index].exp_x2);
    }

    return count;
}
