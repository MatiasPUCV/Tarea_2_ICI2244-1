#include "turist.h"

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

turist* TuristCreate()
{
    turist* result = malloc(sizeof(turist));

    result->pasaportNumber = NULL;

    result->name = NULL;
    result->country = NULL;

    result->favoritePlaces = createList();

    return result;
}

void TuristAddFavPlace(turist* T, const char* place)
{
    pushBack(T->favoritePlaces, &place);
}

void TuristFromStr(const char* str, HashMap* map1, HashMap* map2)
{
    turist* temp = TuristCreate();

    size_t size = strlen(str);
    size_t lastpos = 0;
    int elementCount = 0;

    char** ptrArr[3] = {&temp->pasaportNumber, &temp->name, &temp->country};

    for(size_t i = 0; i < size; i++)
    {

        char c = str[i];
        //printf("%i == %i || %i \n", i, size, c);

        if(c != ',' && c != '\n' && c != ';' && c != '\0')
            continue;

        size_t strsize = i - lastpos - 1;

        // crea la str que representa el elemento y lo puebla
        char* element = calloc(strsize, sizeof(char));
        for (size_t j = 0; j < strsize + 1; j++)
            element[j] = str[j + lastpos];
    
        // Añade el elemento al Turista
        if (elementCount <= 2)
            *ptrArr[elementCount] = element;
        else
            pushFront(temp->favoritePlaces, element);

        lastpos = i + 1;
        elementCount++;
    }

    insertMap(map2, temp->country, temp);

}

void TuristPrint(turist* T)
{
    if (T == NULL)
        return;

    printf("%s, %s, %s", T->pasaportNumber, T->name, T->country);

    char* data = firstList(T->favoritePlaces);
    while (data != NULL)
    {
        printf(", %s", data);
        data = nextList(T->favoritePlaces);
    }

    printf("\n");

}