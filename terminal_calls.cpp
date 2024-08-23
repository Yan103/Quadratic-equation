#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "color_printf.h"
#include "input_output.h"
#include "my_assert.h"
#include "return_codes.h"
#include "solver.h"
#include "struct_equation.h"
#include "tester_solver.h"

int start_programm(const int argc, char *argv[]);

int start_programm(const int argc, char *argv[]) {
    ASSERT(argv != nullptr, "Null pointer was passed");

    int opt = 0, next = 0, startFlag = 0;
    equation quadratic_equation = {};

    while((opt = getopt(argc, argv, "a:sth")) != -1) {
        startFlag = 1;
        switch (opt) {
            case 'h':
                printf("-s starts the input coefficients mode for solving equation (enabled by default)\n"
                       "-t starts the automatic testing mode (by reading data from a file)\n"
                       "-a {number} limited input mode for {number} attempts\n"
                       "-h calls the help commands\n"
                       "if you do not specify parameters, then -s will be used by default\n");
                break;
            case 's':
                input_equation(&quadratic_equation, 0);
                solve_equation(&quadratic_equation);
                output_result(&quadratic_equation);
                break;
            case 't':
                tester_solver();
                break;
            case 'a':
                next = input_equation(&quadratic_equation, atoi(optarg));
                if (next != USER_OUT) {
                    solve_equation(&quadratic_equation);
                    output_result(&quadratic_equation);
                }
                break;
            default:
                printfRed("Flag error!\n");
                return UNKNOWN_FLAG;
        }
    }

    if (startFlag == 0) {
        input_equation(&quadratic_equation, 0);
        solve_equation(&quadratic_equation);
        output_result(&quadratic_equation);
    }

    return SUCCESS;
}
