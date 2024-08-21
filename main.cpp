#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "input_output.h"
#include "solver.h"
#include "struct_equation.h"
#include "nRoots.h"
#include "tester_solver.h"


int main(int argc, char *argv[]) {

    if (argc == 1 || strcmp(argv[1], "--SOLVER") == 0) {
        equation quadratic_equation = {};

        input_equation(&quadratic_equation);
        solve_equation(&quadratic_equation);
        output_result(&quadratic_equation);
    } else if (strcmp(argv[1], "--TESTER") == 0) {
        tester_solver();
    } else {
        printf("Unknown flag!\n");
    }


    return 0;
}
