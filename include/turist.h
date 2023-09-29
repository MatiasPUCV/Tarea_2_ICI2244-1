#ifndef TURIST_H
#define TURIST_H

#include "list.h"
#include "hashmap.h"

typedef struct
{
    char* pasaportNumber;
    char* name;
    char* country;
    List* favoritePlaces;

} turist;

turist* TuristCreate();
turist* TuristFromStr(const char* str);
void TuristCreateFromData(char* pasaportNumber, char* name, char* country, HashMap* map1, HashMap* map2);
void TuristFree(turist* T);

void TuristPrint(turist* T);
void TuristAddFavPlace(turist* T, const char* place);

#endif
