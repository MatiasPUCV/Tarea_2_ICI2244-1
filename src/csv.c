#include "csv.h"

#include "util.h"
#include "turist.h"
#include "point.h"
#include "app.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ShouldEnlarge(HashMap* M)
{
    if (M == NULL)
        return;

    int size70 = M->capacity * 0.7;
    if(size70 <= M->size)
        printf("SI - %i\n", size70);
}

// Convierte un archivo csv a una lista
void ImportfromCsv(const char* filename, dataType type, HashMap* map1, HashMap* map2)
{
    // Consigue la infomación del archivo
    FILE* file = fopen(filename, "r");
    if(file == NULL)
        return;

    char buffer[500];
    fgets(buffer, sizeof(buffer), file);

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

        }

    }    

    fclose(file);
}
