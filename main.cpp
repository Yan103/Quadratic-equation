#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "color_printf.h"
#include "input_output.h"
#include "nRoots.h"
#include "solver.h"
#include "struct_equation.h"
#include "tester_solver.h"


int main(int argc, char *argv[]) {
    if (argc == 1 || strcmp(argv[1], "--solver") == 0) {
        equation quadratic_equation = {};
        input_equation(&quadratic_equation);
        solve_equation(&quadratic_equation);
        output_result(&quadratic_equation);
    } else if (strcmp(argv[1], "--tester") == 0) {
        tester_solver();
    } else if (strcmp(argv[1], "--help") == 0) {
        printf("--solver starts the input coefficients mode for solving equation (enabled by default)\n");
        printf("--tester starts the automatic testing mode (by reading data from a file)\n");
        printf("--help calls the help commands\n");
    } else {
        printfRed("Unknown flag!\n");
        return -1;
    }

    return 0;
}
