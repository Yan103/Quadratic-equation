/*!
    \file
    File with the declaration of the my_assert function
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

const char CAT[] = " /\\..../\\\n"
                   "(.'*..*'.)     MEOW :3\n"
                   " .==**==. \n"
                   "(.\\.||./.)~~^^\n";

const char HELP_TEXT[] = "-s starts the input coefficients mode for solving equation (enabled by default)\n"
                       "-t {file name} starts the automatic testing mode (by reading data from a file)\n"
                       "-a {number} limited input mode for {number} attempts\n"
                       "-h calls the help commands\n"
                       "if you do not specify parameters, then -s will be used by default\n";

/*!
    Function that starts the program (if available, use command line arguments)
    \param [in] argc - argc argument
    \param [in] argv - argv argument
*/
int start_programm(const int argc, char *argv[]);

#endif // TERMINAL_CALLS_H
