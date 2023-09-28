#ifndef CSV_H
#define CSV_H

#include "hashmap.h"

typedef enum dataType
{
    Turist, Point
} dataType;

void ImportfromCsv(const char* filename, dataType type, HashMap* map1, HashMap* map2);

#endif