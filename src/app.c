#include "app.h"
#include "csv.h"

#include <stdio.h>
#include <stdlib.h>

void AppImportCsv(HashMap* map1, HashMap* map2, HashMap* map3, HashMap* map4);
void AppTuristByCountry(HashMap* map);

char* HelperGetStr(const char* msg)
{
    printf("\n");
    char* str = malloc(sizeof(char) * 100);
    printf(msg);
    scanf("%s", str);
    printf("\n", str);

    return str;
}

void AppTick(bool* close, HashMap* map1, HashMap* map2, HashMap* map3, HashMap* map4)
{
    int code;

    printf("-----------------------------------\n");
    printf(" 1) Registrar punto de interés\n");
    printf(" 2) Mostrar datos de punto de interés\n");
    printf(" 3) Eliminar punto de interés\n");
    printf(" 4) Registrar turista\n");
    printf(" 5) Agregar lugar favorito a turista\n");
    printf(" 6) Mostrar turistas por país\n");
    printf(" 7) Mostrar todos los puntos de interés de un tipo\n");
    printf(" 8) Importar puntos de interés y turistas desde archivos CSV\n");
    printf(" 9) Exportar puntos de interés y turistas a archivos CSV\n");
    printf(" 0) Cerrar\n");
    printf("-----------------------------------\n");

    scanf("%i", &code);

    switch (code)
    {
    case 6:
        AppTuristByCountry(map2);
        break;
    case 8:
        AppImportCsv(map1, map2, map3, map4);
        break;
    
    default:
        *close = false;
        break;
    }
}

void AppAddFavPlace(HashMap* map)
{
    
}

void AppImportCsv(HashMap* map1, HashMap* map2, HashMap* map3, HashMap* map4)
{
    char* file = HelperGetStr("Insertar nombre archivo: ");

    int option;
    printf("[0] turistas, [1] punto de interes: ");
    scanf("%i", &option);
    printf("\n");
    
    if (option == 0)
        ImportfromCsv(file, Turist, map1, map2);
    else
        ImportfromCsv(file, Point, map3, map4);
    
    free(file);
}


void AppTuristByCountry(HashMap* map)
{
    printf("[%i]\n", map->size);
}
