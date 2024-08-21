#ifndef COLOR_PRINTF_H
#define COLOR_PRINTF_H

#include <stdio.h>

//-----------------------------------------------------
//! @note Function reads data from a file intended for testing the program and writes it to an array of structures (test_ptr)
#define printfRed(s, a...) printf("\033[1;31m" s "\033[1;0m", ## a)

//-----------------------------------------------------
//! @note Function reads data from a file intended for testing the program and writes it to an array of structures (test_ptr)
#define printfGreen(s, a...) printf("\033[1;32m" s "\033[1;0m", ## a)

#endif // COLOR_PRINTF_H
