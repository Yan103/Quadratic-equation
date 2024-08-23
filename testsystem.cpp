#include <math.h>
#include <stdio.h>

#include "my_assert.h"
#include "nRoots.h"
#include "solver.h"
#include "struct_equation.h"

const double EPS = 1e-4;

bool IS_EQUAL(double x, double y);

bool IS_EQUAL(double x, double y) {
    return fabs(x - y) < EPS;
}

int TestSystem(int test_number, double a, double b, double c, nRoots exp_nRoots, double exp_x1, double exp_x2);

int TestSystem(int test_number, double a, double b, double c, nRoots exp_nRoots, double exp_x1, double exp_x2) {
    int count = 0;
    struct equation quadratic_equation = {a, b, c, b * b - 4 * a * c, UNKNOWN, UNKNOWN, UNKNOWN};
    solve_equation(&quadratic_equation);

    if (exp_nRoots == NO_ROOTS && quadratic_equation.nRoots == NO_ROOTS) {
        count++;
    } else {
        if (exp_nRoots != quadratic_equation.nRoots || !IS_EQUAL(exp_x1, quadratic_equation.x1) || !IS_EQUAL(exp_x2, quadratic_equation.x2)) {
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
