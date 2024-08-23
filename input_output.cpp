#include "input_output.h"

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "color_printf.h"
#include "my_assert.h"
#include "nRoots.h"
#include "return_codes.h"

static int validStr_check(double *coeff_a, double *coeff_b, double *coeff_c) {
   bool valid_str = true;
   for (int s = getchar(); s != '\n' && s != EOF; s = getchar()) {
      if (!isspace(s)) {
         valid_str = false;
      }
   }

   if (valid_str && isfinite(*coeff_a) && isfinite(*coeff_b) && isfinite(*coeff_c)) {
      return SUCCESS;
   } else {
      printfRed("Incorrect input, enter real numbers!\n");
      return INPUT_ERROR;
   }
}

// Input coefficients
int input_equation(equation *e_ptr, int attempts) {
   ASSERT(e_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(attempts), "An indeterminate number (INF or NAN) was received");

   int input_count = 0;
   double coeff_a = 0, coeff_b = 0, coeff_c = 0;
   char message[10] = {};

   while (1) {
      if (attempts != 0) {
         printf("Enter coefficents a, b and c (%d attempts remained, enter quit to exit): ", attempts - input_count++);
      } else {
         printf("Enter coefficents a, b and c (enter quit to exit): ");
      }

      if (scanf("%lf %lf %lf", &coeff_a, &coeff_b, &coeff_c) == 3) {

         int next = validStr_check(&coeff_a, &coeff_b, &coeff_c);
         if (next == SUCCESS) {
            break;
         }

      } else {
         if (scanf("%s", message) == 1) {
            if (strcmp("quit", message) == 0) {
               printf("You wanted to leave :(\n");
               return USER_OUT;
            }

         for (int s = getchar(); s != '\n' && s != EOF; s = getchar()) {};
         printfRed("Incorrect input, enter numbers or 'quit' to exit!\n");
         }
      }
      if (attempts == input_count && attempts != 0) {
            printf("Input attempts have ended...\n");
            return USER_OUT;
      }
   }
   ASSERT(isfinite(e_ptr->a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(e_ptr->b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(e_ptr->c), "An indeterminate number (INF or NAN) was received");

   e_ptr->a = coeff_a;
   e_ptr->b = coeff_b;
   e_ptr->c = coeff_c;
   e_ptr->D = coeff_b * coeff_b - 4 * coeff_a * coeff_c;
   e_ptr->x1 = e_ptr->x2 = e_ptr->nRoots = UNKNOWN;
   return SUCCESS;
}

int output_result(const equation *q_equation) {
   ASSERT(q_equation != nullptr, "Null pointer was passed");
   ASSERT(isfinite(q_equation->a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(q_equation->c), "An indeterminate number (INF or NAN) was received");
   ASSERT(q_equation->nRoots != UNKNOWN, "Internal function execution error");

   switch (q_equation->nRoots) {
      case NO_ROOTS:
         printf("The equation has no real roots\n");
         return SUCCESS;
      case ONE_ROOT:
         printf("The equation has 1 root: %g\n", q_equation->x1);
         return SUCCESS;
      case TWO_ROOTS:
         printf("The equation has 2 root: %g and %g\n", q_equation->x1, q_equation->x2);
         return SUCCESS;
      case INF_ROOTS:
         printf("The equation has an infinite number of solutions\n");
         return SUCCESS;
      case UNKNOWN:
         printf("Something went wrong...\n");
         return SUCCESS;
      default:
         printfRed("Something went wrong...\n");
         return PROGRAMM_ERROR;
   }
}
