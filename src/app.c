#include "app.h"
#include "csv.h"
#include "point.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void AppRegisterPoint(HashMap* map1, HashMap* map2);
void AppGetPointData(HashMap* map);
void AppErasePoint(HashMap* map);
void AppRegisterTurist(HashMap* map1, HashMap* map2);
void AppAddFavPlace(HashMap* map);
void AppTuristByCountry(HashMap* map);
void AppGetPointByType(HashMap* map);

void AppImportCsv(HashMap* map1, HashMap* map2, HashMap* map3, HashMap* map4);

char* GetStrFromInput(const char* msg)
{
    printf("\x1b[38;2;193;159;36mInserte %s:\x1b[0m ", msg);
    char* str = malloc(sizeof(char) * 100);
    if (scanf("%[^\n]", str) != 1)
    {
        free(str);
        return NULL;
    }

    // Limpia el buffer de entrada
    int c; while ((c = getchar()) != '\n' && c != EOF);

    return str;
}

void AppTick(bool* close, HashMap* map1, HashMap* map2, HashMap* map3, HashMap* map4)
{
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

    int code;
    if (scanf("%i", &code) != 1)
    {
        Error("No se pudo conseguir el numero");
        return;
    }

    // Limpia el buffer de entrada
    int c; while ((c = getchar()) != '\n' && c != EOF);

    switch (code)
    {
    case 1:
        AppRegisterPoint(map3, map4);
        break;
    case 2:
        AppGetPointData(map3);
        break;
    case 3:
        AppErasePoint(map3);
        break;
    case 4:
        AppRegisterTurist(map1, map2);
        break;
    case 5:
        AppAddFavPlace(map1);
        break;
    case 6:
      AppTuristByCountry(map2);
      break;
    case 7:
      AppGetPointByType(map4);
      break;

    case 8:
        AppImportCsv(map1, map2, map3, map4);
        break;

    default:
      *close = false;
        break;
    }

}

void AppRegisterPoint(HashMap* map1, HashMap* map2)
{
    char* name        = GetStrFromInput("nombre del punto");
    char* type        = GetStrFromInput("tipo del punto");
    char* direction   = GetStrFromInput("direccíon del punto");
    char* schedule    = GetStrFromInput("horario del punto");
    char* description = GetStrFromInput("despripción del punto");

    if(name == NULL || type == NULL || direction == NULL || schedule == NULL || description == NULL)
    {
        Error("No se pudo obtener datos");
    }
  
    PointCreateFromData(name, type, direction, schedule, description, map1, map2);

    Success("\nNuevo Punto creado exitosamente!\n");

    free(name); free(type); free(direction); free(schedule); free(description);
}

void AppGetPointData(HashMap* map)
{
    char* name = GetStrFromInput("nombre del punto");

    Pair* pair = searchMap(map, name);
    if(pair == NULL || pair->key == NULL || pair->value == NULL)
    {
      Error("Punto no encontrado");
      return;
    }

    PointPrint(pair->value);
    printf("\n");

    free(name);
}

void AppErasePoint(HashMap* map)
{
    char* name = GetStrFromInput("nombre del punto");

    Pair* pair = searchMap(map, name);
    if(pair == NULL || pair->key == NULL || pair->value == NULL)
    {
      Error("El punto no existe");
      return;
    }

    eraseMap(map, name);
    free(name);
}

void AppRegisterTurist(HashMap* map1, HashMap* map2)
{
    char* pasaportNumber = GetStrFromInput("numero de pasaporte");
    char* name           = GetStrFromInput("nombre");
    char* country        = GetStrFromInput("país");

    TuristCreateFromData(pasaportNumber, name, country, map1, map2);

    Success("Turista registrado exitosamente!");
  
    free(pasaportNumber); free(name); free(country);
}

void AppAddFavPlace(HashMap* map)
{
    char* pass = GetStrFromInput("numero de pasaporte");

    Pair* pair = searchMap(map, pass);
    if(pair == NULL || pair->key == NULL || pair->value == NULL)
    {
        Error("Turistas no encontrado");
        return;
    }

    char* fav = GetStrFromInput("lugar favorito");

    TuristAddFavPlace(pair->value, fav);
}

void AppTuristByCountry(HashMap* map)
{
    char* country = GetStrFromInput("país del turista");

    Pair* pair = searchMap(map, country);
    if(pair == NULL || pair->key == NULL || pair->value == NULL)
    {
      Error("Turista no encontrado");
      return;
    }

    TuristPrint(pair->value);
    printf("\n");

    free(country);
}


void AppImportCsv(HashMap* map1, HashMap* map2, HashMap* map3, HashMap* map4)
{
    char* file = GetStrFromInput("nombre archivo");

    int option;
    printf("[0] turistas, [1] punto de interes: ");
    if (scanf("%i", &option) != 1)
    {
        Error("No se pudo conseguir el numero");
        return;
    }
    printf("\n");
    
    if (option == 0)
        ImportfromCsv(file, Turist, map1, map2);
    else
        ImportfromCsv(file, Point, map3, map4);
    
    free(file);

    Success("\nArchivo importado!\n");
}

void AppGetPointByType(HashMap* map)
{
    char* type = GetStrFromInput("tipo de los puntos");

    Pair* pair = searchMap(map, type);
    if(pair == NULL || pair->key == NULL || pair->value == NULL)
    {
      Error("Tipo no encontrado");
      return;
    }

    point* ptr = pair->value;
    char* temp = ptr->type;

    while(ptr != NULL || strcmp(temp, ptr->type) == 0)
    {    
        PointPrint(ptr);
        printf("\n");

        Pair* temp = nextMap(map);
        if(pair == NULL || pair->key == NULL || pair->value == NULL)
          return;

        ptr = (point*)temp->value;
    }

    free(type);
}
