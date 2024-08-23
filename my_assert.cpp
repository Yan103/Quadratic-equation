#include <cstdlib>
#include <stdio.h>

#include "color_printf.h"

void my_assert(bool condition, const char *textError, const char *file, const char *func, int line);

void my_assert(bool condition, const char *textError, const char *file, const char *func, int line) {
    if (!(condition)) {
        printfRed("%s in: %s -> %s -> %d", textError, file, func, line);
        abort(); // todo abort
    }
}

