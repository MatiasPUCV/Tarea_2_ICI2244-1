#include "point.h"
#include "turist.h"
#include "hashmap.h"
#include "csv.h"

#include "app.h"

#include "stdlib.h"
#include <stdio.h>

int main()
{
    HashMap* m1 = createMap(300);
    HashMap* m2 = createMap(200);

    ImportfromCsv("turistas.csv", 0, m1, m2);

    AppTuristByCountry(m2, "Italia");
    
}