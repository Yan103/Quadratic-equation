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

/*!
    Function that starts the program (if available, use command line arguments)
    \param [in] argc - argc argument
    \param [in] argv - argv argument
*/
int start_programm(const int argc, char *argv[]);

#endif // TERMINAL_CALLS_H
