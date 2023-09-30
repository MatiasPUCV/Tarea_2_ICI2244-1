#include "turist.h"
#include "util.h"

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

void TuristAddFavPlace(turist* T, char* place)
{
    pushBack(T->favoritePlaces, place);
}

turist* TuristFromStr(const char* str)
{
    turist* temp = TuristCreate();

    size_t size = strlen(str);
    size_t lastpos = 0;
    int elementCount = 0;

    char** ptrArr[3] = {&temp->pasaportNumber, &temp->name, &temp->country};

    for(size_t i = 0; i < size; i++)
    {
        char c = str[i];
        if(c != ',' && c != '\n' && c != ';' && c != '\0')
            continue;

        size_t strsize = i - lastpos - 1;

        // crea la str que representa el elemento y lo puebla
        char* element = calloc(101, sizeof(char));
        for (size_t j = 0; j < strsize + 1; j++)
            element[j] = str[j + lastpos];
    
        // Añade el elemento al Turista
        if (elementCount <= 2)
            *ptrArr[elementCount] = element;
        else
            pushBack(temp->favoritePlaces, element);

        lastpos = i + 1;
        elementCount++;
    }

    return temp;
}

void TuristCreateFromData(char* pasaportNumber, char* name, char* country, HashMap* map1, HashMap* map2)
{
    turist* t = TuristCreate();
    t->pasaportNumber = pasaportNumber;
    t->name = name;
    t->country = country;

    insertMap(map1, t->pasaportNumber, t);
    insertMap(map2, t->country, t);

    ShouldEnlarge(map1);
    ShouldEnlarge(map2);
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

void TuristFree(turist* T)
{
    if (T == NULL)
        return;

    free(T->country);
    free(T->favoritePlaces);
    free(T->name);
    free(T->pasaportNumber);

    free(T);
}

void TuristPrintToStream(FILE* file, turist* T)
{
    if (T == NULL)
        return;

    fprintf(file, "%s,%s,%s", T->pasaportNumber, T->name, T->country);

    char* data = firstList(T->favoritePlaces);
    while (data != NULL)
    {
        fprintf(file, ";%s", data);
        data = nextList(T->favoritePlaces);
    }

    fprintf(file, "\n");
}