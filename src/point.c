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

point* PointFromStr(const char* str)
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
        
        // TODO: Revisar que ningun elemento no tenga más de 100 caracteres

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
        return NULL;
    }

    return temp;
}

void PointPrint(point* P)
{
    if (P == NULL)
        return;

    printf("%s, %s, %s, %s", P->name, P->type, P->direction, P->schedule, P->description);
}