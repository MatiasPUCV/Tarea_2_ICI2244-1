#include "csv.h"

#include "util.h"
#include "turist.h"
#include "app.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char* GetFile(const char* filename);

// Convierte un archivo csv a una lista
void ImportfromCsv(const char* filename, int type, HashMap* map1, HashMap* map2)
{
    // Consigue la infomación del archivo
    char* file = GetFile(filename);
    if(file == NULL)
        return;

    // iniciealiza variables
    size_t size = strlen(file);
    size_t lastpos = 0;
    bool first = true;

    for(size_t i = 0; i < size; i++)
    {
        char c = file[i];

        // Solo continua si se encontor un '\n' o no hay un tamaño invalido
        if(c != '\n')
            continue;

        size_t strsize = i - lastpos - 1;
        
        if (strsize == -1)
            continue;

        // Crea y puebla una str que contendara una fila del csv
        char* str = calloc(strsize + 2, sizeof(char));
        for (size_t j = 0; j < strsize + 1; j++)
        {
            str[j] = file[j + lastpos];
        }
        // Añade un ',' al final para facilitar la lectura de la fila
        if (str[strsize] != ',')
            str[strsize + 1] = ',';

        if(!first)
        {
            // Pasa la fila a un libro y lo guarda en la lista
            TuristFromStr(str, map1, map2);
        }
        else
        {
            // Ignora la primera fila del archivo
            first = false;
        }

        free(str);
        lastpos = i + 1;
    }

    free(file);
}

char* GetFile(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("El Archivo no existe\n");
        return NULL;
    }

    // Consigue el tamaño del archivo
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file) + 2;
    fseek(file, 0, SEEK_SET);

    // Guarda memoria para la str
    char* contents = calloc(size, sizeof(char));

    // Lee el archivo
    fread(contents, 1, size, file);

    // añade un salto de linea para hacer la lectuta más facil
    contents[size - 2] = '\n';

    fclose(file);

    return contents;
}