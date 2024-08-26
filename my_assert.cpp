#include "my_assert.h"

#include <cstdlib>

/// Terminates the execution of the program when an error is detected
void my_assert(bool condition, const char *text_error, const char *file, const char *func, int line) {
    if (!(condition)) {
        printf(RED("%s in: %s -> %s -> %d"), text_error, file, func, line);
        abort();
    }
}
