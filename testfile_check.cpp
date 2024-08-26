#include "testfile_check.h"

#include "my_assert.h"

/// Start checking expected data with valid ones
int testfile_check(tests *test_ptr, const int number_tests) {
    ASSERT(test_ptr != nullptr, "Null pointer was passed");

    /// size_t N_TESTS = sizeof(test_ptr) / sizeof(tests);

    int count = 0;
    for (int test_index = 0; test_index < number_tests; test_index++)
    {
        count += TestSystem(test_index + 1,
                            test_ptr[test_index].coeff_a,
                            test_ptr[test_index].coeff_b,
                            test_ptr[test_index].coeff_c,
                            test_ptr[test_index].exp_nRoots,
                            test_ptr[test_index].exp_x1,
                            test_ptr[test_index].exp_x2);
    }

    return count;
}
