#include "app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "turist.h"
#include "csv.h"

int main()
{   
    // Crea los mapas
    HashMap* map1 = createMap(50);
    HashMap* map2 = createMap(50);
    HashMap* map3 = createMap(50);
    HashMap* map4 = createMap(50);

    //ImportfromCsv("turistas.csv", Turist, arr[0], arr[1]);
    
    // Bucle principal
    bool flag = true;
    while (flag)
    {
        AppTick(&flag, map1, map2, map3, map4);
    }

    // Libera memoria (quiero un free() varidico T_T)
    free(map1); free(map2);
    free(map3); free(map4);
}