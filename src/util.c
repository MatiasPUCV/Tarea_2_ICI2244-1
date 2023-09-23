#include "util.h"

#include "stdio.h"
#include "stdarg.h"

void Error(const char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    printf("\x1b[38;2;135;10;21m[error]: \x1b[0m");
    vfprintf(stdout, fmt, args);
    printf("\n");

    va_end(args);
}