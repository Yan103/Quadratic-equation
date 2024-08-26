#include "solver.h"

#include <math.h>
#include <stdio.h>

#include "my_assert.h"
#include "nRoots.h"
#include "struct_equation.h"

static const double EPS = 1e-8;
static const int PLUG = -1;

/// Compare number with 0
static bool is_zero(double number) {
   return fabs(number) < EPS;
}

/// Swap 2 numbers
static void swap(double *first, double *second) {
   double tmp = *first;
   *first = *second;
   *second = tmp;
}

// Any number is a solution of equation
static void has_inf_roots(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->nRoots == UNKNOWN, "Internal function execution error");

   equation_ptr->nRoots = INF_ROOTS;
   equation_ptr->x1 = equation_ptr->x2 = PLUG;
}

// Equation has no real roots
static void doesnt_have_real_roots(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->nRoots == UNKNOWN, "Internal function execution error");

   equation_ptr->nRoots = NO_ROOTS;
   equation_ptr->x1 = equation_ptr->x2 = PLUG;
}

// Equation becomes linear
static void solve_linear_equation(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->nRoots == UNKNOWN, "Internal function execution error");

   equation_ptr->nRoots = ONE_ROOT;
   equation_ptr->x1 = (is_zero(equation_ptr->coeff_c)) ? 0 : -equation_ptr->coeff_c / equation_ptr->coeff_b;
   equation_ptr->x2 = PLUG;
}

// Solving quadratic equation
static void solve_quadratic_equation(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->nRoots == UNKNOWN, "Internal function execution error");

   if (!is_zero(equation_ptr->D)) {
      equation_ptr->nRoots = TWO_ROOTS;
      const double sqrt_D = sqrt(equation_ptr->D);
      equation_ptr->x1 = (-equation_ptr->coeff_b - sqrt_D) / (2 * equation_ptr->coeff_a);
      equation_ptr->x2 = (-equation_ptr->coeff_b + sqrt_D) / (2 * equation_ptr->coeff_a);

      if (equation_ptr->x1 > equation_ptr->x2) {
         swap(&equation_ptr->x1, &equation_ptr->x2);
      }
   } else {
      equation_ptr->nRoots = ONE_ROOT;
      equation_ptr->x1 = (is_zero(equation_ptr->coeff_b)) ? 0 : -equation_ptr->coeff_b / (2 * equation_ptr->coeff_a);
      equation_ptr->x2 = PLUG;
   }
}

// Solving the equation (get information about the number of roots and the roots themselves)
void solve_equation(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->nRoots == UNKNOWN, "Internal function execution error");

   if (is_zero(equation_ptr->coeff_a)) {
      if (is_zero(equation_ptr->coeff_b)) {
         if (is_zero(equation_ptr->coeff_c)) {
               has_inf_roots(equation_ptr);
            } else {
               doesnt_have_real_roots(equation_ptr);
            }
        } else {
           solve_linear_equation(equation_ptr);
        }
   } else {
        if (equation_ptr->D < 0) {
            doesnt_have_real_roots(equation_ptr);
        } else {
            solve_quadratic_equation(equation_ptr);
        }
   }
}

