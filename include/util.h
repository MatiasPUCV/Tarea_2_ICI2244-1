#ifndef UTIL_H
#define UTIL_H

#include "hashmap.h"

// printf pero en rojo
void Error(const char* fmt, ...);

// printf pero en verde
void Success(const char* fmt, ...);

// revisa si supera el 70% de su capacidad y si es el caso lo agranda
void ShouldEnlarge(HashMap* M);

#endif // UTIL_H