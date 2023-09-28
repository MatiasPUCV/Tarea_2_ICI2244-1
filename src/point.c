#include "point.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

point* PointCreate()
{
    point* result = malloc(sizeof(point));

    result->name = NULL;
    result->type = NULL;
    result->direction = NULL;
    result->schedule = NULL;
    result->description = NULL;

    return result;
}

void PointFromStr(const char* str, HashMap* map1, HashMap* map2)
{
    size_t size = strlen(str);
    size_t lastpos = 0;
    int elementCount = 0;

    point* temp = PointCreate();

    char** ptrArr[5] = {&temp->name, &temp->type, &temp->direction, &temp->schedule, &temp->description};

    for(size_t i = 0; i < size; i++)
    {
        char c = str[i];
        if(c != ',' && c != '\n')
            continue;

        size_t strsize = i - lastpos - 1;

        if (strsize > 100)
        {
            Error("Str muy larga, ignornado datos...");
            return;
        }

        // crea la str que representa el elemento y lo puebla
        char* element = calloc(101, sizeof(char));
        for (size_t j = 0; j < strsize + 1; j++)
            element[j] = str[j + lastpos];

        // Añade el elemento al Punto de Interes
        *ptrArr[elementCount] = element;

        lastpos = i + 1;
        elementCount++;
    }

    // Error
    if (elementCount > 5)
    {
        Error("Datos insufiecientes para un Punto de Interes: %i", elementCount);
        return;
    }


    insertMap(map1, temp->name, temp);
    insertMap(map2, temp->type, temp);


    long size70 = map1->capacity * 0.7;

    if (map1->capacity >= size70)
    {
        enlarge(map1);
        enlarge(map2);
    }
}

void PointPrint(point* P)
{
    if (P == NULL)
        return;

    printf("%s, %s, %s, %s", P->name, P->type, P->direction, P->schedule, P->description);
}