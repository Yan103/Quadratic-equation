/*!
    \file
    A file describing the input and output functions
*/

#include "input_output.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "color_printf.h"
#include "my_assert.h"
#include "number_roots.h"
#include "return_codes.h"

/*!
   Checking the string for correct input
   \param [in] coeff_a - Coefficient A
   \param [in] coeff_b - Coefficient B
   \param [in] coeff_c - Coefficient C
   \return If the string is valid, it returns 1, otherwise 0
*/
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
      printf(RED("Incorrect input, enter real numbers!\n"));

      return INPUT_ERROR;
   }
}

/*!
   Function that, in case of an error, prints where it occurred and terminates the program
   \param [out] equation_ptr - equation pointer
   \param [in]      attempts - Number of input attempts
   \return Returns the status of the completed coefficient entry
*/
int input_equation(equation *equation_ptr, const int attempts) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(attempts), "An indeterminate number (INF or NAN) was received");

   int input_count = 0;
   double coeff_a = 0, coeff_b = 0, coeff_c = 0;
   char message[100] = {};

   while (1) {
      if (attempts != 0) {
         printf("Enter coefficents a, b and c (%d attempts remained, enter quit to exit): ", attempts - input_count++);
      } else {
         printf("Enter coefficents a, b and c (enter quit to exit): ");
      }

      if (scanf("%lf %lf %lf", &coeff_a, &coeff_b, &coeff_c) == 3) {

         int next = validStr_check(&coeff_a, &coeff_b, &coeff_c);

         if (next == SUCCESS) break;


      } else {
         if (scanf("%100s", message) == 1) {
            if (strcmp("quit", message) == 0) {
               printf("You wanted to leave :(\n");

               return USER_OUT;
            }

         for (int s = getchar(); s != '\n' && s != EOF; s = getchar()) {};

         printf(RED("Incorrect input, enter numbers or 'quit' to exit!\n"));
         }
      }

      if (attempts == input_count && attempts != 0) {
         printf("Input attempts have ended...\n");

         return USER_OUT;
      }
   }

   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");

   equation_ptr->coeff_a = coeff_a;
   equation_ptr->coeff_b = coeff_b;
   equation_ptr->coeff_c = coeff_c;
   equation_ptr->D = coeff_b * coeff_b - 4 * coeff_a * coeff_c;
   equation_ptr->x1 = equation_ptr->x2 = equation_ptr->number_roots = UNKNOWN;

   return SUCCESS;
}

/*!
   Function that outputs information about the roots of the equation or their absence
   \param [in] equation_ptr - equation pointer
   \return Returns the status of the completed coefficient output
*/
int output_result(const equation *equation_ptr) {
   ASSERT(equation_ptr != nullptr, "Null pointer was passed");
   ASSERT(isfinite(equation_ptr->coeff_a), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_b), "An indeterminate number (INF or NAN) was received");
   ASSERT(isfinite(equation_ptr->coeff_c), "An indeterminate number (INF or NAN) was received");
   ASSERT(equation_ptr->number_roots != UNKNOWN, "Internal function execution error");

   switch (equation_ptr->number_roots) {
      case NO_ROOTS:
         printf("The equation has no real roots\n");

         return SUCCESS;
      case ONE_ROOT:
         printf("The equation has 1 root: %lg\n", equation_ptr->x1);

         return SUCCESS;
      case TWO_ROOTS:
         printf("The equation has 2 root: %lg and %lg\n", equation_ptr->x1, equation_ptr->x2);

         return SUCCESS;
      case INF_ROOTS:
         printf("The equation has an infinite number of solutions\n");

         return SUCCESS;
      case UNKNOWN:
         printf("Something went wrong...\n");

         return SUCCESS;
      default:
         printf(RED("Something went wrong...\n"));

         return PROGRAMM_ERROR;
   }
}
