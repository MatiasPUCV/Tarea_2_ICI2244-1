#ifndef CSV_H
#define CSV_H

#include "hashmap.h"

// Tipos de datos, en este caso turistas y puntos de interes
typedef enum dataType
{
    Turist,
    Point
} dataType;

// importa datos desde un csv y los inserta en sus respectivos mapa
int ImportfromCsv(const char* filename, dataType type, HashMap* map1, HashMap* map2);

// Exporta datos de un mapa en formato csv
void ExportToCsv(char* filename, dataType type, HashMap* map);

#endif