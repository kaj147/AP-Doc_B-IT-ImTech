#include <iostream>
#include "vector.h"
#include "tijd.h"

int main()
{
    Vector2 pos(10.0f, 5.0f);
    Vector2 snelheid(2.0f, 1.0f);
    Vector2 nieuw = pos + (snelheid * 2.0f); // Resultaat: (14, 7)

}
