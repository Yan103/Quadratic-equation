#include <assert.h>
#include <stdio.h>

#include "color_printf.h"

void my_assert(bool condition, const char *textError);

void my_assert(bool condition, const char *textError) {
    if (!(condition)) {
        printfRed("%s", textError);
        abort(); // todo abort
    }
}
