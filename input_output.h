#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "struct_equation.h"

//-----------------------------------------------------
//! @param [out] e_ptr - equation pointer
//!
//! @note The function starts the process of entering the coefficients of the equation, if additional parameters
//!       are specified in the console at startup, it processes them;
//!       --ENDLESS -> infinite number of input attempts (enter "quit" to end the program)
//!       --ATTEMPTS {int number (obligatory parametr)} ->  limited number of attempts, if they are all over - the end of the program (if 0 is passed, the program will not start)
//!       if you do not specify parameters, then --ENDLESS will be used by default
void input_equation(equation *e_ptr);


//-----------------------------------------------------
//! @param [in] e_ptr - equation pointer
//!
//! @note Outputs information about the roots of the equation or their absence
void output_result(const equation *q_equation);

//


#endif //INPUT_OUTPUT_H
