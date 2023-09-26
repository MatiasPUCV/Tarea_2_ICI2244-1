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
void TuristFromStr(const char* str, HashMap* map1, HashMap* map2);

void TuristPrint(turist* T);

void TuristAddFavPlace(turist* T, const char* place);

#endif
