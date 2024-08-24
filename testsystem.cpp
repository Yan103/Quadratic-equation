#include "testsystem.h"

#include <math.h>
#include <stdio.h>

#include "my_assert.h"

static const double EPS = 1e-5;

bool IS_EQUAL(double first, double second) {
    return fabs(first - second) < EPS;
}

int TestSystem(int test_number, double coeff_a, double coeff_b, double coeff_c,
               nRoots exp_nRoots, double exp_x1, double exp_x2)
    {
    int count = 0;
    struct equation quadratic_equation = {.coeff_a = coeff_a,
                                          .coeff_b = coeff_b,
                                          .coeff_c = coeff_c,
                                          .D = coeff_b * coeff_b - 4 * coeff_a * coeff_c,
                                          .x1 = UNKNOWN,
                                          .x2 = UNKNOWN,
                                          .nRoots = UNKNOWN};
    solve_equation(&quadratic_equation);

    if (exp_nRoots == NO_ROOTS && quadratic_equation.nRoots == NO_ROOTS) {
        count++;
    } else {
        if (exp_nRoots != quadratic_equation.nRoots
            || !IS_EQUAL(exp_x1, quadratic_equation.x1)
            || !IS_EQUAL(exp_x2, quadratic_equation.x2))
        {
            printf("Error: Test %d (Get: x1=%lg x2=%lg nRoot=%d, \
                    expected: x1=%lg x2=%lg nRoot=%d)\n", test_number, \
                    quadratic_equation.x1, quadratic_equation.x2, quadratic_equation.nRoots, \
                    exp_x1, exp_x2, exp_nRoots);
        } else {
            count++;
        }
    }
    return count;
}
