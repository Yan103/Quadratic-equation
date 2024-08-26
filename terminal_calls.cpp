/*!
    \file
    The file with the description of the starting function
*/

#include "terminal_calls.h"

/*!
    Function that starts the program (if available, use command line arguments)
    \param [in] argc - argc argument
    \param [in] argv - argv argument
    \return Returns the status of the start function execution
*/
int start_solve_programm(const int argc, char *argv[]) {
    ASSERT(argv != nullptr, "Null pointer was passed");

    int opt = 0, next = 0;
    bool start_flag = false;
    equation quadratic_equation = {};

    while((opt = getopt(argc, argv, "a:tshc")) != -1) {
        start_flag = true;

        switch (opt) {
            case 'h':
                printf("%s", HELP_TEXT);

                return SUCCESS;
            case 's':
                next = input_equation(&quadratic_equation, 0);
                if (next != USER_OUT) {
                    solve_equation(&quadratic_equation);
                    output_result(&quadratic_equation);
                }

                return SUCCESS;
            case 't':
                if (argc == 3) {
                    tester_solver(argv[2]);
                }
                else {
                    printf(RED("Your file has not been found! The standard test file (tests.txt) is launched:\n"));
                    tester_solver(TESTS_FILENAME);
                }

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
            case 'c' :
                printf("%s", CAT);

                return SUCCESS;
            default:
                printf(RED("Flag error!\n"));

                return UNKNOWN_FLAG;
        }
    }

    if (!start_flag) {
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
