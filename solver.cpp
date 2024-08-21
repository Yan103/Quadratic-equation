#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "roots_status.h"
#include "struct_equation.h"

const double EPS = 1e-8;
#define IS_ZERO(x) (fabs(x) < EPS)

void solve_equation(equation *q_equation);

// Any number is a solution of equation
static void has_inf_roots(equation *q_equation) {
   assert(q_equation);
   assert(isfinite(q_equation->a));
   assert(isfinite(q_equation->b));
   assert(isfinite(q_equation->c));
   assert(q_equation->nRoots == UNKNOWN);

   q_equation->nRoots = INF_ROOTS;
}

// Equation has no real roots
static void doesnt_have_real_roots(equation *q_equation) {
   assert(q_equation);
   assert(isfinite(q_equation->a));
   assert(isfinite(q_equation->b));
   assert(isfinite(q_equation->c));
   assert(q_equation->nRoots == UNKNOWN);

   q_equation->nRoots = NO_ROOTS;
}

// Equation becomes linear
static void solve_linear_equation(equation *q_equation) {
   assert(q_equation);
   assert(isfinite(q_equation->a));
   assert(isfinite(q_equation->b));
   assert(isfinite(q_equation->c));
   assert(q_equation->nRoots == UNKNOWN);

   q_equation->nRoots = ONE_ROOT;
   q_equation->x1 = (IS_ZERO(q_equation->c)) ? 0 : -q_equation->c / q_equation->b;
}

// Solving quadratic equation
static void solve_quadratic_equation(equation *q_equation) {
   assert(q_equation);
   assert(isfinite(q_equation->a));
   assert(isfinite(q_equation->b));
   assert(isfinite(q_equation->c));
   assert(q_equation->nRoots == UNKNOWN);

   if (!IS_ZERO(q_equation->D)) {
      q_equation->nRoots = TWO_ROOTS;
      const double sqrt_D = sqrt(q_equation->D);
      q_equation->x1 = (-q_equation->b - sqrt_D) / (2 * q_equation->a);
      q_equation->x2 = (-q_equation->b + sqrt_D) / (2 * q_equation->a);
   } else {
      q_equation->nRoots = ONE_ROOT;
      q_equation->x1 = (IS_ZERO(q_equation->b)) ? 0 : -q_equation->b / (2 * q_equation->a);
   }
}

// Solving the equation (get information about the number of roots and the roots themselves)
void solve_equation(equation *q_equation) {
   assert(q_equation);
   assert(isfinite(q_equation->a));
   assert(isfinite(q_equation->b));
   assert(isfinite(q_equation->c));
   assert(q_equation->nRoots == UNKNOWN);

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
