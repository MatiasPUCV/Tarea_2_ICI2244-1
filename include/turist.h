#ifndef TURIST_H
#define TURIST_H

#include "list.h"

typedef struct
{
    int pasaportNumber;
    const char* name;
    const char* country;
    List* favoritePlaces;

} turist;

turist* TuristCreate();
void TuristAddFavPlace(turist* T, const char* place);

#endif
