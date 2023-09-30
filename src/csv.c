#include "csv.h"

#include "util.h"
#include "turist.h"
#include "point.h"
#include "app.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Convierte un archivo csv a una lista
int ImportfromCsv(const char* filename, dataType type, HashMap* map1, HashMap* map2)
{
    // Consigue la infomación del archivo
    FILE* file = fopen(filename, "r");
    if(file == NULL)
        return -1;

    char buffer[500];

    // Ignora primera linea del archivo
    if(fgets(buffer, sizeof(buffer), file)) {}
  
    while(fgets(buffer, sizeof(buffer), file))
    {
        if(type == Turist)
        {
            turist* t = TuristFromStr(buffer);

            insertMap(map1, t->pasaportNumber, t);
            insertMap(map2, t->country, t);
        }
        else if(type == Point)
        {
            point* p = PointFromStr(buffer);
            insertMap(map1, p->name, p);
            insertMap(map2, p->type, p);
        }

        ShouldEnlarge(map1);
        ShouldEnlarge(map2);
    }    

    fclose(file);
    return 0;
}

// Revisa si un par es valido
bool InvalidPair(Pair* pair)
{
  if(pair == NULL || pair->key == NULL || pair->value == NULL)
    return true;

  return false;
}

// exporta a un csv
void ExportToCsv(char* filename, dataType type, HashMap* map)
{
    // Crea el archivo
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        Error("El archivo no existe");
        return;
    }

    long size = map->capacity;
    for (long l = 0; l < size; l++)
    {   
        Pair* pair = map->buckets[l];
        if(InvalidPair(pair))
            continue;
      
        if(type == Turist)
            TuristPrintToStream(file, pair->value);
        else if(type == Point)
            PointPrintToStream(file, pair->value);
      
        pair = nextMap(map);
    }

    fclose(file);
}