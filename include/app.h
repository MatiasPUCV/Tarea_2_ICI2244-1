#ifndef APP_H
#define APP_H

#include "hashmap.h"
#include "turist.h"

#include <stdbool.h>

// funcion que se ejecuata constantemente en el bucle principal
void AppTick(bool* close, HashMap* map1, HashMap* map2, HashMap* map3, HashMap* map4);

#endif // APP_H