#include <stdio.h>

#include "input_output.h"
#include "solver.h"
#include "struct_equation.h"
#include "nRoots.h"



int main() {
    equation quadratic_equation = {};

    input_equation(&quadratic_equation);
    solve_equation(&quadratic_equation);
    output_result(&quadratic_equation);

    return 0;
}
