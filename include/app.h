#ifndef APP_H
#define APP_H

#include "hashmap.h"
#include "turist.h"

void AppInitMaps();

void AppTuristByCountry(HashMap* map, char* country);

#endif // APP_H