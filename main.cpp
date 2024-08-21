#include <stdio.h>

#include "input_output.h"
#include "solver.h"
#include "struct_equation.h"


int main(int argc, char *argv[]) {
    struct equation quadratic_equation = {};

    input_equation(argc, argv, &quadratic_equation);
    solve_equation(&quadratic_equation);
    output_result(&quadratic_equation);

    return 0;
}
