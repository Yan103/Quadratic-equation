#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "color_printf.h"
#include "input_output.h"
#include "return_codes.h"
#include "solver.h"
#include "struct_equation.h"
#include "tester_solver.h"
#include "terminal_calls.h"

// int argc, char *argv[]
int main() {

    int a = 0;
    scanf("%d", &a);
    if (a == NULL || !isfinite(a)) {
        printfRed("Error");
        exit(INPUT_ERROR);
    }
    // start_programm(argc, argv);

    return SUCCESS;
}
