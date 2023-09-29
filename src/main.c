#include "app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "turist.h"
#include "csv.h"

int main()
{
    HashMap* map1 = createMap(100);
    HashMap* map2 = createMap(100);
    HashMap* map3 = createMap(100);
    HashMap* map4 = createMap(100);

    //ImportfromCsv("turistas.csv", Turist, arr[0], arr[1]);

    bool flag = true;
    while (flag)
    {
        AppTick(&flag, map1, map2, map3, map4);
    }

    
    printf("END\n");

    free(map1);
    free(map2);
    free(map3);
    free(map4);
}