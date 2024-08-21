#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "nRoots.h"
#include "struct_equation.h"

void input_equation(equation *e_ptr);
void output_result(const equation *q_equation);

// Input coefficients
void input_equation(equation *e_ptr) {
   assert(e_ptr);

   double a = 0, b = 0, c = 0;

   while (1) {
      printf("Enter coeficents a, b and c (enter quit to exit): ");
      if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
         bool valid_str = true;
         for (int s = getchar(); s != '\n' && s != EOF; s = getchar()) {
            if (!isspace(s)) {
               valid_str = false;
            }
         }
         if (valid_str) {
            break;
         } else {
            printf("Incorrect input, enter numbers!\n");
         }
      } else {
         for (int s = getchar(); s != '\n' && s != EOF; s = getchar());
         printf("Incorrect input, enter numbers!\n");
      }
   }

   assert(isfinite(a));
   assert(isfinite(b));
   assert(isfinite(c));

   e_ptr->a = a;
   e_ptr->b = b;
   e_ptr->c = c;
   e_ptr->D = b * b - 4 * a * c;
   e_ptr->x1 = e_ptr->x2 = e_ptr->nRoots = UNKNOWN;
}

// Result output
void output_result(const equation *q_equation) {
   assert(q_equation);
   assert(isfinite(q_equation->a));
   assert(isfinite(q_equation->b));
   assert(isfinite(q_equation->c));
   assert(q_equation->nRoots != UNKNOWN);

   switch (q_equation->nRoots) {
      case NO_ROOTS:
         printf("The equation has no real roots\n");
         break;
      case ONE_ROOT:
         printf("The equation has 1 root: %g\n", q_equation->x1);
         break;
      case TWO_ROOTS:
         printf("The equation has 2 root: %g and %g\n", q_equation->x1, q_equation->x2);
         break;
      case INF_ROOTS:
         printf("The equation has an infinite number of solutions\n");
         break;
      case UNKNOWN:
         printf("Something went wrong...\n");
         break;
      default:
         printf("Something went wrong...\n");
         break;
    }
}


