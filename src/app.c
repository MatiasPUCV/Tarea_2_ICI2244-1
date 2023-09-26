#include "app.h"




void AppInitMaps()
{

}


void AppTuristByCountry(HashMap* map, char* country)
{
    Pair* temp = searchMap(map, "Italia");

    TuristPrint(temp->value);
}