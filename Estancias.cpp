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

void menuPrincipal(string nombres[])
{
    int opcion, i;

    rlutil::setColor(rlutil::WHITE);

    cout<< "1 - JUGAR" <<endl
        << "2 - ESTADISTICAS" <<endl
        << "3 - CERDITOS" <<endl
        << "------------------" <<endl
        << "0 - SALIR" <<endl<<endl;
    cin>>opcion;

    rlutil::cls();

    switch(opcion)
    {
        case 1:
                for(i=0; i<=1; i++)
                {
                    cout<< "Ingrese nombre del jugador " <<i+1 <<endl;
                    cin>>nombres[i];
                }
        break;
    }

    cout<< "PRESIONE CUALQUIER TECLA PARA CONTINUAR...";
    rlutil::anykey();
    rlutil::cls();
}

void tiraPrimero(string nombres[], bool &juegaPrimero)
{
    int i, j, dados[2][2], suma[2], dadoMayor[2], x[2], y[2];;

    for(i=0;i<2;i++)
    {
        cout<< nombres[i] <<endl << "PRESIONA CUALQUIER TECLA PARA TIRAR" <<endl;
        rlutil::anykey();

        tirarDado(x, y, true);

        for(j=0;j<2;j++)
        {
            dados[i][j]= azarDado();
            mostrarDado(dados[i][j], x[j], y[j]);
        }

        rlutil::anykey();
        rlutil::cls();

        suma[i]= dados[i][0] + dados[i][1];
        dadoMayor[i]=funcionDadoMayor(dados[i][0],dados[i][1]);

        if(i==0) cout<< "A SUPERAR " << dados[i][0] << " + " << dados[i][1] << " = " << suma[i] <<endl;
    }

    if(suma[0]==suma[1])
    {
        if(dadoMayor[0]==dadoMayor[1])
        {
             cout<< "HUBO EMPATE, VUELVAN A TIRAR" <<endl;
             rlutil::anykey();
             rlutil::cls();
             tiraPrimero(nombres, juegaPrimero);
        }
        else if(dadoMayor[0]>dadoMayor[1])
        {
            juegaPrimero=0;
            quienPrimero(nombres, 0, " tuvo el dado de mayor valor");
        }
        else
        {
            juegaPrimero=1;
            quienPrimero(nombres, 1, " tuvo el dado de mayor valor");
        }
    }
    else if(suma[0]>suma[1])
    {
        juegaPrimero=0;
        quienPrimero(nombres, 0, " la suma de sus dados es mayor");
    }
    else
    {
        juegaPrimero=1;
        quienPrimero(nombres, 1, " la suma de sus dados es mayor");
    }

    cout<< "PRESIONA CUALQUIER TECLA PARA CONTINUAR...";
    rlutil::anykey();
    rlutil::cls();
}

void ronda(string nombres[], int acumTrufas[], int &contRondas, int contLanzamientos[], int acumTrufasRonda[], bool juegaPrimero, bool &hundido)
{
    //Turno del primer jugador
    turno(nombres, acumTrufas, contRondas, contLanzamientos, acumTrufasRonda, juegaPrimero, hundido);

    //Turno del segundo jugador
    turno(nombres, acumTrufas, contRondas, contLanzamientos, acumTrufasRonda, !juegaPrimero, hundido);

    contLanzamientos[0]=0;
    contLanzamientos[1]=0;
    acumTrufas[0] += acumTrufasRonda[0];
    acumTrufas[1] += acumTrufasRonda[1];
    acumTrufasRonda[0]=0;
    acumTrufasRonda[1]=0;
}
