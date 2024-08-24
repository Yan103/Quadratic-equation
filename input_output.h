#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "struct_equation.h"

//-----------------------------------------------------
///< @param [out] e_ptr - equation pointer
///< @param [in] attempts - number of input attempts
///< @note  The function starts the process of entering the coefficients of the equation, if additional parameters
///<        are specified in the console at startup, it processes them;
int input_equation(equation *equation_ptr, int attempts);

//-----------------------------------------------------
///< @param [in] e_ptr - equation pointer
///<
///< @note Outputs information about the roots of the equation or their absence
int output_result(const equation *equation_ptr);

#endif //INPUT_OUTPUT_H
