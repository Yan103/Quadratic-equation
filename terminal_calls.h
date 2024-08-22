#ifndef TERMINAL_CALLS_H
#define TERMINAL_CALLS_H

#include <stdio.h>
#include <unistd.h>

#include "color_printf.h"
#include "input_output.h"
#include "return_codes.h"
#include "solver.h"
#include "struct_equation.h"
#include "tester_solver.h"

int start_programm(int argc, char *argv[]);

#endif // TERMINAL_CALLS_H
