#ifndef UTIL_H
#define UTIL_H

#include "hashmap.h"

void Error(const char* fmt, ...);
void Success(const char* fmt, ...);

void ShouldEnlarge(HashMap* M);

#endif // UTIL_H