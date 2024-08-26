/*!
    \file
    A file describing the input and output functions
*/

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "struct_equation.h"

/*!
    Function that, in case of an error, prints where it occurred and terminates the program
    \param [out] equation_ptr - equation pointer
    \param [in]      attempts - Number of input attempts
    \return Returns the status of the completed coefficient entry
*/
int input_equation(equation *equation_ptr, const int attempts);

/*!
   Function that outputs information about the roots of the equation or their absence
   \param [in] equation_ptr - equation pointer
   \return Returns the status of the completed coefficient output
*/
int output_result(const equation *equation_ptr);

#endif //INPUT_OUTPUT_H
