#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "my_assert.h"
#include "nRoots.h"
#include "struct_equation.h"

const double EPS = 1e-8;

bool IS_ZERO(double x);
void solve_equation(equation *q_equation);
static void swap(double *first, double *second);

const int PLUG = -1;

bool IS_ZERO(double x) {
   return fabs(x) < EPS;
}

static void swap(double *first, double *second) {
   double tmp = *first;
   *first = *second;
   *second = tmp;
}

// Solving the equation (get information about the number of roots and the roots themselves)
void solve_equation(equation *q_equation) {
   ASSERT(q_equation != nullptr, "Null pointer was passed");
   ASSERT(isfinite(q_equation->a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->c), "An indeterminate number (INF or NAN) was received");
   ASSERT(q_equation->nRoots == UNKNOWN, "Internal function execution error");

   if (IS_ZERO(q_equation->a)) {
      if (IS_ZERO(q_equation->b)) {
         if (IS_ZERO(q_equation->c)) {
               has_inf_roots(q_equation);
            } else {
               doesnt_have_real_roots(q_equation);
            }
        } else {
           solve_linear_equation(q_equation);
        }
   } else {
        if (q_equation->D < 0) {
            doesnt_have_real_roots(q_equation);
        } else {
            solve_quadratic_equation(q_equation);
        }
   }
}

// Any number is a solution of equation
static void has_inf_roots(equation *q_equation) {
   ASSERT(q_equation != nullptr, "Null pointer was passed");
   ASSERT(isfinite(q_equation->a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->c), "An indeterminate number (INF or NAN) was received");
   ASSERT(q_equation->nRoots == UNKNOWN, "Internal function execution error");

   q_equation->nRoots = INF_ROOTS;
   q_equation->x1 = q_equation->x2 = PLUG;
}

// Equation has no real roots
static void doesnt_have_real_roots(equation *q_equation) {
   ASSERT(q_equation != nullptr, "Null pointer was passed");
   ASSERT(isfinite(q_equation->a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->c), "An indeterminate number (INF or NAN) was received");
   ASSERT(q_equation->nRoots == UNKNOWN, "Internal function execution error");

   q_equation->nRoots = NO_ROOTS;
   q_equation->x1 = q_equation->x2 = PLUG;
}

// Equation becomes linear
static void solve_linear_equation(equation *q_equation) {
   ASSERT(q_equation != nullptr, "Null pointer was passed");
   ASSERT(isfinite(q_equation->a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->c), "An indeterminate number (INF or NAN) was received");
   ASSERT(q_equation->nRoots == UNKNOWN, "Internal function execution error");

   q_equation->nRoots = ONE_ROOT;
   q_equation->x1 = (IS_ZERO(q_equation->c)) ? 0 : -q_equation->c / q_equation->b;
   q_equation->x2 = PLUG;
}

// Solving quadratic equation
static void solve_quadratic_equation(equation *q_equation) {
   ASSERT(q_equation != nullptr, "Null pointer was passed");
   ASSERT(isfinite(q_equation->a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->c), "An indeterminate number (INF or NAN) was received");
   ASSERT(q_equation->nRoots == UNKNOWN, "Internal function execution error");

   if (!IS_ZERO(q_equation->D)) {
      q_equation->nRoots = TWO_ROOTS;
      const double sqrt_D = sqrt(q_equation->D);
      q_equation->x1 = (-q_equation->b - sqrt_D) / (2 * q_equation->a);
      q_equation->x2 = (-q_equation->b + sqrt_D) / (2 * q_equation->a);
      if (q_equation->x1 > q_equation->x2) {
         swap(&q_equation->x1, &q_equation->x2);
      }
   } else {
      q_equation->nRoots = ONE_ROOT;
      q_equation->x1 = (IS_ZERO(q_equation->b)) ? 0 : -q_equation->b / (2 * q_equation->a);
      q_equation->x2 = PLUG;
   }
}
