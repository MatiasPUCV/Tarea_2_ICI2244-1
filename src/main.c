#include "util.h"
#include "point.h"

#include "stdlib.h"
#include <stdio.h>

int main()
{
    point* temp = PointFromStr("Museo del Arte,Museo,Calle Central 123,9:00-18:00,Una colección impresionante de arte contemporáneo\n");

    PointPrint(temp);

    free(temp);
}