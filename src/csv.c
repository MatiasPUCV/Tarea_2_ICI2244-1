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
void ImportfromCsv(const char* filename, dataType type, HashMap* map1, HashMap* map2)
{
    // Consigue la infomación del archivo
    FILE* file = fopen(filename, "r");
    if(file == NULL)
        return;

    char buffer[500];
  
    if(fgets(buffer, sizeof(buffer), file))
    {
      
    }

    while(fgets(buffer, sizeof(buffer), file))
    {
        if(type == Turist)
        {
            turist* t = TuristFromStr(buffer);

            insertMap(map1, t->pasaportNumber, t);
            insertMap(map2, t->country, t);

            ShouldEnlarge(map1);
            ShouldEnlarge(map2);
        }
        else if(type == Point)
        {
            point* p = PointFromStr(buffer);

            insertMap(map1, p->name, p);
            insertMap(map2, p->type, p);

            ShouldEnlarge(map1);
            ShouldEnlarge(map2);
        }

    }    

    fclose(file);
}
