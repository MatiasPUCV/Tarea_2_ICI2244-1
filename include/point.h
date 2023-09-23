#ifndef POINT_H
#define POINT_H

#include "hashmap.h"

typedef struct 
{
    char* name;
    char* type;
    char* direction;
    char* schedule;
    char* description;

} point;

point* PointCreate();
point* PointFromStr(const char* str);

void PointPrint(point* P);

static HashMap* MapPointName;
static HashMap* MapPointType;

#endif // POINT_H