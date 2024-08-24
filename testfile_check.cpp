#include "testfile_check.h"

#include "my_assert.h"

int testfile_check(tests *test_ptr) {
    ASSERT(test_ptr != nullptr, "Null pointer was passed");

    int count = 0;
    for (int test_index = 0; test_index < N_TESTS; test_index++)
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
