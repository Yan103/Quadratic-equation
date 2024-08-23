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

//-----------------------------------------------------
///< @param [in] argc - argc argument
///< @param [in] argv - argv argument
///< @note Starts the program (if available, use command line arguments)
int start_programm(const int argc, char *argv[]);

#endif // TERMINAL_CALLS_H
