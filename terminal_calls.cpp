#include "terminal_calls.h"

/// Start the programm
int start_programm(const int argc, char *argv[]) {
    ASSERT(argv != nullptr, "Null pointer was passed");

    int opt = 0, next = 0;
    bool startFlag = false;
    equation quadratic_equation = {};

    while((opt = getopt(argc, argv, "a:sth")) != -1) {
        startFlag = true;
        switch (opt) {
            case 'h':
                printf("-s starts the input coefficients mode for solving equation (enabled by default)\n"
                       "-t starts the automatic testing mode (by reading data from a file)\n"
                       "-a {number} limited input mode for {number} attempts\n"
                       "-h calls the help commands\n"
                       "if you do not specify parameters, then -s will be used by default\n");
                return SUCCESS;
            case 's':
                next = input_equation(&quadratic_equation, 0);
                if (next != USER_OUT) {
                    solve_equation(&quadratic_equation);
                    output_result(&quadratic_equation);
                }
                return SUCCESS;
            case 't':
                tester_solver("tests.txt");
                return SUCCESS;
            case 'a':
                next = input_equation(&quadratic_equation, atoi(optarg));
                if (next != USER_OUT) {
                    solve_equation(&quadratic_equation);
                    output_result(&quadratic_equation);
                    return SUCCESS;
                } else {
                    return USER_OUT;
                }
            default:
                printfRed("Flag error!\n");
                return UNKNOWN_FLAG;
        }
    }

    if (!startFlag) {
        next = input_equation(&quadratic_equation, 0);
        if (next != USER_OUT) {
            solve_equation(&quadratic_equation);
            output_result(&quadratic_equation);
            return SUCCESS;
        } else {
            return USER_OUT;
        }
    }
    return SUCCESS;
}
