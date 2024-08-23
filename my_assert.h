#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <assert.h>
#include <stdio.h>

#include "color_printf.h"

//-----------------------------------------------------
///< @param [in] condition - the condition that needs to be checked
///< @param [in] textError - the text indicating the error
///<
///< @note The function checks the condition and, if necessary, reports an error and ends the execution of the program
void my_assert(bool condition, const char *textError);

#endif // MY_ASSERT_H
