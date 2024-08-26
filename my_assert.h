/*!
    \file
    File with the declaration of the my_assert function
*/

#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdio.h>

#include "color_printf.h"

/// Passes data about the file, function, and string to the my_assert function
#define ASSERT(condition, text_error) my_assert(condition, text_error, __FILE__, __func__, __LINE__)

/*!
    Function that, in case of an error, prints where it occurred and terminates the program
    \param [in]  condition - the condition that needs to be checked
    \param [in] text_error - error description text
    \param [in]       file - the name of the file where the error occurred
    \param [in]       func - the name of the function where the error occurred
    \param [in]       line - the number of the line where the error occurred
*/
void my_assert(bool condition, const char *text_error, const char *file, const char *func, int line);

#endif // MY_ASSERT_H
