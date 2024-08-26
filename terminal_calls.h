/*!
    \file
    The file with the description of the starting function
*/

#ifndef TERMINAL_CALLS_H
#define TERMINAL_CALLS_H

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

/// Name of default test file
static const char TESTS_FILENAME[] = "tests.txt";

/// Cute cat picture
const char CAT[] = " /\\..../\\\n"
                   "(.'*..*'.)   \033[35mMEOW :3\033[0m\n"
                   " .==**==. \n"
                   "(.\\.||./.)~~^^\n";
/// Help test
const char HELP_TEXT[] = "-s starts the input coefficients mode for solving equation (enabled by default)\n"
                         "-t {file name} starts the automatic testing mode (by reading data from a file)\n"
                         "-a {number} limited input mode for {number} attempts\n"
                         "-h calls the help commands\n"
                         "if you do not specify parameters, then -s will be used by default\n";

/*!
    Function that starts the program (if available, use command line arguments)
    \param [in] argc - argc argument
    \param [in] argv - argv argument
    \return Returns the status of the start function execution
*/
int start_solve_programm(const int argc, char *argv[]);

#endif // TERMINAL_CALLS_H
