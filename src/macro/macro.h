
#ifndef SANDBOX_MACRO_H
#define SANDBOX_MACRO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void sb_macro_assert(bool assert, const char* cond, const char* file, int line, const char* message);

#define sbassert(cond) sb_macro_assert(cond, "\""#cond"\"", __FILE__, __LINE__, NULL)
#define sbasserts(cond, message) sb_macro_assert(cond, "\""#cond"\"", __FILE__, __LINE__, message)

#endif //SANDBOX_MACRO_H
