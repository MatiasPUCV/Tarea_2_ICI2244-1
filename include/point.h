#ifndef POINT_H
#define POINT_H

#include "hashmap.h"

#include <stdio.h>

typedef struct 
{
    char* name;
    char* type;
    char* direction;
    char* schedule;
    char* description;

} point;

// Crea un punto
point* PointCreate();

// Crea un punto desde una STR
point* PointFromStr(const char* str);

// Crea un punto con la información proporcionada
void PointCreateFromData(char* name, char* type, char* direction, char* schedule, char* description, HashMap* map1, HashMap* map2);

// Imprime un punto en pantalla
void PointPrint(point* P);

// Escribe la información de un punto a un archivo en formato csv
void PointPrintToStream(FILE* file, point* P);

#endif // POINT_H