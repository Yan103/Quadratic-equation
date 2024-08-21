#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "color_printf.h"
#include "nRoots.h"
#include "struct_equation.h"

int input_equation(equation *e_ptr);
int output_result(const equation *q_equation);

// Input coefficients
int input_equation(equation *e_ptr) {
   assert(e_ptr);

   double a = 0, b = 0, c = 0;
   char message[10] = {};

   while (1) {
      printf("Enter coefficents a, b and c (enter quit to exit): ");
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
            printfRed("Incorrect input, enter numbers!\n");
         }
      } else {
         if (scanf("%s", message) == 1) {
            if (strcmp("quit", message) == 0) {
               printf("You wanted to leave)\n");
               return 1;
            }
         for (int s = getchar(); s != '\n' && s != EOF; s = getchar()) {};
         printfRed("Incorrect input, enter numbers or 'quit'!\n");
         }
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
   return 0;
}

int output_result(const equation *q_equation) {
   assert(q_equation);
   assert(isfinite(q_equation->a));
   assert(isfinite(q_equation->b));
   assert(isfinite(q_equation->c));
   assert(q_equation->nRoots != UNKNOWN);

   switch (q_equation->nRoots) {
      case NO_ROOTS:
         printf("The equation has no real roots\n");
         return 0;
      case ONE_ROOT:
         printf("The equation has 1 root: %g\n", q_equation->x1);
         return 0;
      case TWO_ROOTS:
         printf("The equation has 2 root: %g and %g\n", q_equation->x1, q_equation->x2);
         return 0;
      case INF_ROOTS:
         printf("The equation has an infinite number of solutions\n");
         return 0;
      case UNKNOWN:
         printf("Something went wrong...\n");
         return 0;
      default:
         printfRed("Something went wrong...\n");
         return -1;
    }
}


