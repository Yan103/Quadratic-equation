/*!
    \file
    File with colored text output (red and green)
*/

#ifndef COLOR_PRINTF_H
#define COLOR_PRINTF_H

#include <stdio.h>

/// Prints the text in red
#define printfRed(s, a...) printf("\033[1;31m" s "\033[1;0m", ## a)

/// Prints the text in green
#define printfGreen(s, a...) printf("\033[1;32m" s "\033[1;0m", ## a)

#endif // COLOR_PRINTF_H
