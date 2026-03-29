#include <iostream>

int getallen[5] = {10, 20, 30, 40, 50};
int length = sizeof(getallen) / sizeof(getallen[0]);
int *ptr = getallen;
int *backptr = getallen + (length - 1);


//oef4
struct Speler
{
    int health;
    int score;
};

void resetHealthFout(Speler s)
{
    s.health = 100;
}

void resetHealthGoed(Speler* s)
{
    s->health = 100;
}


//oef5
Speler* maakSpelerOpStack()
{
    Speler* s = new Speler();
    s->health = 20;
    s->score = 0;

    return s;
}

//bonus
char lofzang[] = "Zie elk goed Mr.toonet lgek eve ncht nieMw arn m oi Dedeajuimt nstje doodr eat et en de Ceze+ at+Dam s abtijemaat suerper me  deierasles  oodn hae invee  +hCnd #oor beteren zototaalextra rijk als in destemp.";
int* infiltrationPtr = (int*)lofzang;

int main() {
    //std::cout << ptr << std::endl;

    //oef1
    std::cout << "Oef1" << std::endl;

    for (int x = 0; x < length; x++)
    {
        std::cout << &getallen[x] << std::endl; //print geheugen adressen af dit met 4 bits groot dus elke array heeft max 4 bit groot
    }

    //oef2
    std::cout << "Oef2" << std::endl;

    for (int i = 0; i < length; i++)
    {
        *ptr = 7 * (i + 1);
        ptr++;

        std::cout << *(getallen + i) << std::endl;
    }

    //oef3
    std::cout << "Oef3" << std::endl;

    for (int x = 0; x < length; x++)
    {
        std::cout << *(backptr--) << std::endl;
    }

    //oef4
    std::cout << "Oef4" << std::endl;

    Speler speler = Speler{20,0};

    resetHealthFout(speler);
    std::cout << speler.health << std::endl;
    resetHealthGoed(&speler);
    std::cout << speler.health << std::endl;

    //oef5
    std::cout << "Oef5" << std::endl;

    Speler* geestPtr = maakSpelerOpStack();

    //std::cout << geestPtr->health << std::endl; //breekt programma doordat die niet meer bestaat

    //oef6
    std::cout << "Oef6" << std::endl;

    std::cout << geestPtr->health << std::endl;

    delete geestPtr;

    //bonus
    std::cout << "Bonus" << std::endl;

    for (int x = 0; x < 41; x++)
    {
        std::cout << (char)*infiltrationPtr;
        infiltrationPtr++;
    }
}