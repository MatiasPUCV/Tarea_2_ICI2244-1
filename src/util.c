#include "util.h"

#include "stdio.h"
#include "stdarg.h"

// printf() pero con "error:" de sufijo en rojo
void Error(const char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    printf("\x1b[38;2;135;10;21merror: \x1b[0m");
    vfprintf(stdout, fmt, args);
    printf("\n");

    va_end(args);
}

void Success(const char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    printf("\x1b[38;2;40;150;35m");
    vfprintf(stdout, fmt, args);
    printf("\x1b[0m\n");

    va_end(args);
}

void ShouldEnlarge(HashMap* M)
{
    if (M == NULL)
        return;

    int size70 = M->capacity * 0.7;
    if(size70 <= M->size)
        printf("SI - %i\n", size70);
}