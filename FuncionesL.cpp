#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <wchar.h>

#include "rlutil.h"
#include "Estancias.h"
#include "FuncionesL.h"
#include "FuncionesG.h"

using namespace std;

int azarDado(){
    int valorDado = (rand() % 6)+ 1;
    return valorDado;
}

int funcionDadoMayor(int d1, int d2)
{
    if(d1>d2) return d1;
    else return d2;
}

void tirarDado(int x[], int y[], bool estancia)
{
        if(estancia==true)
    {
        x[0]=(rand()%2)+1;
        y[0]=(rand()%4)+5;
        x[1]=(rand()%1)+10;
        y[1]=(rand()%4)+5;
    }
    else
    {
        x[0]= 2;
        y[0]=(rand()%5)+13;
        x[1]=10;
        y[1]=(rand()%5)+13;
        x[2]=18;
        y[2]=(rand()%5)+13;
    }
}

void turno(string nombres[], int acumTrufas[], int &contRondas, int contLanzamientos[], int acumTrufasRonda[], bool juegaPrimero, bool &hundido)
{
    char continuar;
    bool bandera=false, cedeTurno;

    do{
        rlutil::cls();

        mostrarInfo(nombres, acumTrufas, contRondas, contLanzamientos, acumTrufasRonda, juegaPrimero);

        cout<< "PRESIONA CUALQUIER TECLA PARA TIRAR";
        rlutil::anykey();
        cedeTurno=lanzamiento(acumTrufas, acumTrufasRonda, juegaPrimero, hundido);

        contLanzamientos[juegaPrimero]++;

        if(cedeTurno==true)
        {
            cout<< "PRESIONA CUALQUIER TECLA PARA CONTINUAR...";
            rlutil::anykey();
            break;
        }

        do{
            cout<< "Continuar? (S/N)" <<endl;
            cin>>continuar;

            switch(continuar)
            {
                case 's': case 'S':
                    bandera=true;
                break;
                case 'n': case 'N':
                    bandera=true;
                break;
                default:
                    cout<<"opcion incorrecta, vuelva a intentarlo." <<endl;
                    bandera=false;

                break;
            }

        }while(bandera==false);

    }while((continuar=='s')||(continuar=='S'));
}

bool lanzamiento(int acumTrufas[], int acumTrufasRonda[], bool juegaPrimero, bool &hundido)
{
    int  i, cantDados, contUnos=0, dados[3]={}, x[3], y[3];

    if(((acumTrufas[0]+acumTrufasRonda[0]>=50)&&(acumTrufas[1]+acumTrufasRonda[1]>=50)) || hundido==true)
    {
        cantDados=3;
        hundido=true;
    }
    else cantDados=2;

    tirarDado(x, y, false);

    for(i=0; i<cantDados; i++)
    {
        dados[i]=azarDado();
        mostrarDado(dados[i], x[i], y[i]);
    }

    if(cantDados==2)
    {
        if(dados[0]==dados[1])
        {
            if(dados[0]==1)
            {
                hundido=true;
                hundeBarro(acumTrufas, acumTrufasRonda, juegaPrimero);
                return true;
            }
            else
            {
                oink(acumTrufasRonda, juegaPrimero, dados, cantDados);
                return false;
            }
        }
        else
        {
            if(dados[0]==1 || dados[1]==1)
            {
                pierdeTrufas(acumTrufasRonda, juegaPrimero);
                return true;
            }
            else
            {
                acumulaTrufas(acumTrufasRonda, juegaPrimero, dados, cantDados);
                return false;
            }
        }
    }
    else
    {
        if((dados[0]==dados[1])&&(dados[0]==dados[2]))
        {
            if(dados[0]==1)
            {
                darTrufasAlRival(acumTrufas, acumTrufasRonda, juegaPrimero);
                return true;
            }
            else
            {
                oink(acumTrufasRonda, juegaPrimero, dados, cantDados);
                return false;
            }
        }
        else
        {
            for(i=0; i<3; i++)
            {
                if(dados[i]==1) contUnos++;
            }

            if(contUnos>0)
            {
                if(contUnos==2)
                {
                    hundeBarro(acumTrufas, acumTrufasRonda, juegaPrimero);
                    return true;
                }
                else
                {
                    pierdeTrufas(acumTrufasRonda, juegaPrimero);
                    return true;
                }
            }
            else
            {
                acumulaTrufas(acumTrufasRonda, juegaPrimero, dados, cantDados);
                return false;
            }
        }
    }
}

void acumulaTrufas(int acumTrufasRonda[], bool juegaPrimero, int dados[], int cantDados)
{
    int suma=0;
    for(int i=0; i<cantDados; i++)
    {
        suma += dados[i];
    }
    acumTrufasRonda[juegaPrimero]+=suma;

    acumulaTrufas(suma);
}

void oink(int acumTrufasRonda[], bool juegaPrimero, int dados[], int cantDados)
{
    int suma=0, total;
    for(int i=0; i<cantDados; i++)
    {
        suma+=dados[i];
    }
    total=suma*2;
    acumTrufasRonda[juegaPrimero]+=total;

    oink(total);
}

void pierdeTrufas(int acumTrufasRonda[], bool juegaPrimero)
{
    acumTrufasRonda[juegaPrimero]=0;

    pierdeTrufas();
}

void hundeBarro(int acumTrufas[], int acumTrufasRonda[], bool juegaPrimero)
{
    acumTrufas[juegaPrimero]=0;
    acumTrufasRonda[juegaPrimero]=0;

    hundeBarro();
}

void darTrufasAlRival(int acumTrufas[], int acumTrufasRonda[], bool juegaPrimero)
{
    acumTrufas[!juegaPrimero]+= acumTrufas[juegaPrimero] + acumTrufasRonda[juegaPrimero];
    acumTrufas[juegaPrimero]=0;
    acumTrufasRonda[juegaPrimero]=0;

    darTrufasAlRival();
}
