/*!
   \file
   A file with a description of the functions for solving the equation
*/

#include "solver.h"

#include <math.h>
#include <stdio.h>

#include "my_assert.h"
#include "number_roots.h"
#include "struct_equation.h"

static const double EPS = 1e-8; /// A small value to compare numbers of the type
static const int PLUG = -1;     /// Special value to keep track of the number of roots

/*!
   The function compares a number with zero
   \param [in] number - number
   \return Returns 1 if the number is zero, otherwise 0
*/
static bool is_zero(double number) {
   return fabs(number) < EPS;
}

/*!
   The function changes the values of two pointers
   \param [out] equation_ptr - equation pointer
   \param [out] equation_ptr - equation pointer
*/
static void swap(double *first, double *second) {
   double tmp = *first;
   *first = *second;
   *second = tmp;
}

/*!
   The function records that the equation has an infinite number of solutions
   \param [out] equation_ptr - equation pointer
*/
static void has_inf_roots(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->number_roots == UNKNOWN, "Internal function execution error");

   equation_ptr->number_roots = INF_ROOTS;
   equation_ptr->x1 = equation_ptr->x2 = PLUG;
}

/*!
   The function records that the equation has no valid solutions
   \param [out] equation_ptr - equation pointer
*/
static void doesnt_have_real_roots(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->number_roots == UNKNOWN, "Internal function execution error");

   equation_ptr->number_roots = NO_ROOTS;
   equation_ptr->x1 = equation_ptr->x2 = PLUG;
}

/*!
   The function solves the linear equation (a == 0)
   \param [out] equation_ptr - equation pointer
*/
static void solve_linear_equation(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->number_roots == UNKNOWN, "Internal function execution error");

   equation_ptr->number_roots = ONE_ROOT;
   equation_ptr->x1 = (is_zero(equation_ptr->coeff_c)) ? 0 : -equation_ptr->coeff_c / equation_ptr->coeff_b;
   equation_ptr->x2 = PLUG;
}

/*!
   The function solves the square equation (a != 0)
   \param [out] equation_ptr - equation pointer
*/
static void solve_quadratic_equation(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->number_roots == UNKNOWN, "Internal function execution error");

   if (!is_zero(equation_ptr->D)) {
      equation_ptr->number_roots = TWO_ROOTS;
      const double sqrt_D = sqrt(equation_ptr->D);
      equation_ptr->x1 = (-equation_ptr->coeff_b - sqrt_D) / (2 * equation_ptr->coeff_a);
      equation_ptr->x2 = (-equation_ptr->coeff_b + sqrt_D) / (2 * equation_ptr->coeff_a);

      if (equation_ptr->x1 > equation_ptr->x2) {
         swap(&equation_ptr->x1, &equation_ptr->x2);
      }

   } else {
      equation_ptr->number_roots = ONE_ROOT;
      equation_ptr->x1 = (is_zero(equation_ptr->coeff_b)) ? 0 : -equation_ptr->coeff_b / (2 * equation_ptr->coeff_a);
      equation_ptr->x2 = PLUG;
   }
}

/*!
   The function starts the process of solving the equation
   \param [in] equation_ptr - equation pointer
*/
void solve_equation(equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->number_roots == UNKNOWN, "Internal function execution error");

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
