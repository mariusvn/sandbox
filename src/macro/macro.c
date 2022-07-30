#include "macro.h"

void sb_macro_assert(bool assert, const char* cond, const char* file, int line, const char* message) {
    if (!assert) {
        if (message) {
            fprintf(stderr, "FAILED ASSERTION\n%s: %s [%s:%d]\n", message, cond, file, line);
        } else {
            fprintf(stderr, "FAILED ASSERTION\n%s [%s:%d]\n", cond, file, line);
        }
        exit(1);
    }
}