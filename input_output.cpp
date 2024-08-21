#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "roots_status.h"
#include "struct_equation.h"

static void input_coefficients(equation *e_ptr, int attempts);
void output_result(const equation *q_equation);
void input_equation(int argc, char *argv[], equation *e_ptr);

// Input coefficients
static void input_coefficients(equation *e_ptr, int attempts) {
   assert(e_ptr);
   assert(attempts >= 0);

   double a = 0, b = 0, c = 0;
   int i = 0;

   while (1) {
      if (attempts != 0) {
         if (attempts != i) {
            printf("Enter coeficents a, b and c (%d attempts remain, enter quit to exit): ", attempts - i++);
         } else {
            printf("The attemps are over, bye!\n");
            exit(0);
         }
      } else {
         printf("Enter coeficents a, b and c (enter quit to exit): ");
      }
      if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
         bool flag = true;
         for (int s = getchar(); s != '\n' && s != EOF; s = getchar()) {
            if (!isspace(s)) {
               flag = false;
            }
         }
         if (flag) {
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

// Input equation
void input_equation(int argc, char *argv[], equation *e_ptr) {
   assert(e_ptr);
   assert(argc);
   assert(argv);

   if (argc == 1) {
        input_coefficients(e_ptr, 0);
    } else {
        if (strcmp(argv[1], "--ATTEMPTS") == 0) {
            if (argc == 3) {
               for (int i = 0; i < strlen(argv[2]); i++) {
                  if (!isdigit(argv[2][i])) {
                     printf("Error, if you use --ATTEMPTS, then specify an integer separated by a space!\n");
                     exit(1);
                  }
               }
               if (atoi(argv[2]) != 0) {
               input_coefficients(e_ptr, atoi(argv[2]));
               } else {
                  printf("You entered 0, your attempts are over)\n");
                  exit(1);
               }
            } else {
                printf("Error, if you use --ATTEMPTS, then specify an integer separated by a space!\n");
                exit(1);
            }
        } else if (strcmp(argv[1], "--ENDLESS") == 0) {
            input_coefficients(e_ptr, 0);
        } else {
            printf("Error, Please use only the options --ATTEMPTS {int number} or --ENDLESS!\n");
            exit(1);
        }
    }
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


