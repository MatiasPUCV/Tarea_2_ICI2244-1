#ifndef TURIST_H
#define TURIST_H

#include "list.h"
#include "hashmap.h"

#include <stdio.h>

typedef struct
{
    char* pasaportNumber;
    char* name;
    char* country;
    List* favoritePlaces;

} turist;

// Crea un turista
turist* TuristCreate();
// Crea un turista desde una str
turist* TuristFromStr(const char* str);
// crea un turista con los datos
void TuristCreateFromData(char* pasaportNumber, char* name, char* country, HashMap* map1, HashMap* map2);
void TuristFree(turist* T);

void TuristPrint(turist* T);
void TuristPrintToStream(FILE* file, turist* T);

void TuristAddFavPlace(turist* T, char* place);

#endif
