#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <wchar.h>
#include <stdio.h>

#include "rlutil.h"
#include "Estancias.h"
#include "FuncionesL.h"
#include "FuncionesG.h"

using namespace std;

int main()
{
    system("title GRAN CERDO");
    string nombres[2];
    int contRondas, acumTrufas[2]={}, contLanzamientos[2]={}, acumTrufasRonda[2]={};
    bool juegaPrimero, hundido=false;

    srand(time(NULL));

    cerditoCagando();

    menuPrincipal(nombres);

    tiraPrimero(nombres, juegaPrimero);

    for(contRondas=0; contRondas<5; contRondas++)
    {
        ronda(nombres, acumTrufas, contRondas, contLanzamientos, acumTrufasRonda, juegaPrimero, hundido);
    }

    system("pause>nul");
    return 0;
}
