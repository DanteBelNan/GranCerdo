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

void mostrarDado(int valorDado, int x, int y)
{
    const char a = 219;
    const char b = 223;
    const char c = 220;

    switch(valorDado)
    {
        case 1:
            rlutil::locate(x, y);
            cout<<a<<a<<a<<a<<a<<a<<a;
            rlutil::locate(x, y+1);
            cout<<a<<a<<a<<b<<a<<a<<a;
            rlutil::locate(x, y+2);
            cout<<a<<a<<a<<a<<a<<a<<a;
            rlutil::locate(x, y+3);
            cout<<b<<b<<b<<b<<b<<b<<b;
            break;
        case 2:
            rlutil::locate(x, y);
            cout<<a<<b<<a<<a<<a<<a<<a;
            rlutil::locate(x, y+1);
            cout<<a<<a<<a<<a<<a<<a<<a;
            rlutil::locate(x, y+2);
            cout<<a<<a<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+3);
            cout<<b<<b<<b<<b<<b<<b<<b;
            break;
        case 3:
            rlutil::locate(x, y);
            cout<<a<<b<<a<<a<<a<<a<<a;
            rlutil::locate(x, y+1);
            cout<<a<<a<<a<<b<<a<<a<<a;
            rlutil::locate(x, y+2);
            cout<<a<<a<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+3);
            cout<<b<<b<<b<<b<<b<<b<<b;
            break;
        case 4:
            rlutil::locate(x, y);
            cout<<a<<b<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+1);
            cout<<a<<a<<a<<a<<a<<a<<a;
            rlutil::locate(x, y+2);
            cout<<a<<b<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+3);
            cout<<b<<b<<b<<b<<b<<b<<b;
            break;
        case 5:
            rlutil::locate(x, y);
            cout<<a<<b<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+1);
            cout<<a<<a<<a<<b<<a<<a<<a;
            rlutil::locate(x, y+2);
            cout<<a<<b<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+3);
            cout<<b<<b<<b<<b<<b<<b<<b;
            break;
        case 6:
            rlutil::locate(x, y);
            cout<<a<<b<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+1);
            cout<<a<<b<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+2);
            cout<<a<<b<<a<<a<<a<<b<<a;
            rlutil::locate(x, y+3);
            cout<<b<<b<<b<<b<<b<<b<<b;
            break;
    }
}

void quienPrimero(string nombres[], int jugador, string mensaje)
{
    cout<<"Juega primero " <<nombres[jugador] <<mensaje <<endl;
}

void mostrarInfo(string nombres[], int acumTrufas[], int contRondas, int contLanzamientos[], int acumTrufasRonda[], bool juegaPrimero)
{
    cout<< nombres[0] << ": " <<acumTrufas[0] << " TRUFAS ACUMULADAS" <<endl
        << nombres[1] << ": " <<acumTrufas[1] << " TRUFAS ACUMULADAS" <<endl
        << "TURNO DE " <<nombres[juegaPrimero] <<endl
        << "--------------------------" <<endl
        << "RONDAS #" <<contRondas+1 <<endl
        << "TRUFAS DE LA RONDA: " <<acumTrufasRonda[juegaPrimero] <<endl
        << "LANZAMIENTOS: " <<contLanzamientos[juegaPrimero] <<endl
        << "--------------------------" <<endl<<endl
        << "LANZAMIENTO #" <<contLanzamientos[juegaPrimero]+1 <<endl<<endl;

    return;
}

void acumulaTrufas(int suma)
{
    rlutil::locate(1, 21);
    cout<< "Sumaste " <<suma <<" trufas!!" <<endl;
}

void oink(int total)
{
    rlutil::locate(1, 21);
    cout<< "OINK!!" <<endl;
    cout<< "Tus trufas se multiplican!! :)" <<endl;
    cout<< "Sumaste " <<total <<" trufas!!" <<endl;
}

void pierdeTrufas()
{
    rlutil::locate(1, 21);
    cout<< "Perdiste todas tus trufas acumuladas esta ronda :(" <<endl;
}

void hundeBarro()
{
    rlutil::locate(1, 21);
    cout<< "TE HUNDISTE EN EL BARRO!!" <<endl;
    cout<< "Perdiste todas tus trufas acumuladas esta ronda y las anteriores:(" <<endl;
}

void darTrufasAlRival()
{
    rlutil::locate(1, 21);
    cout<< "Perdiste todas tus trufas acumuladas esta ronda y las anteriores:(" <<endl;
    cout<< "Tus trufas pasan al rival" <<endl;
}

void cerditoCagando()
{
    const char a = 219;
    const char b = 223;
    const char c = 220;
    const int x = 15;
    int i;

    system("title GRAN CERDO");
    rlutil::hidecursor();

    rlutil::locate(x, 2);//GRAN linea 1
    cout<<" "<<" "<<a<<b<<b<<b<<" "<<a<<b<<b<<a<<" "<<a<<b<<b<<a<<" "<<a<<c<<" "<<a;
    rlutil::locate(x, 3);//GRAN linea 2
    cout<<" "<<" "<<a<<" "<<b<<a<<" "<<a<<b<<b<<c<<" "<<a<<b<<b<<a<<" "<<a<<" "<<b<<a;
    rlutil::locate(x, 4);//GRAN linea 3
    cout<<" "<<" "<<b<<b<<b<<b<<" "<<b<<" "<<" "<<b<<" "<<b<<" "<<" "<<b<<" "<<b<<" "<<" "<<b;
    rlutil::locate(x, 5);//CERDO linea 1
    cout<<a<<b<<b<<b<<" "<<a<<b<<b<<b<<" "<<a<<b<<b<<a<<" "<<a<<b<<b<<c<<" "<<a<<b<<b<<a;
    rlutil::locate(x, 6);//CERDO linea 2
    cout<<a<<" "<<" "<<" "<<" "<<a<<b<<b<<" "<<" "<<a<<b<<b<<c<<" "<<a<<" "<<" "<<a<<" "<<a<<" "<<" "<<a;
    rlutil::locate(x, 7);//CERDO linea 3
    cout<<b<<b<<b<<b<<" "<<b<<b<<b<<b<<" "<<b<<" "<<" "<<b<<" "<<b<<b<<b<<" "<<" "<<b<<b<<b<<b;

    do{
        //chanchito
        rlutil::setColor(rlutil::LIGHTMAGENTA);//chanchito para arriba
        rlutil::locate(x+8, 15);
        cout<<" "<<" "<<a<<c<<c<<c<<c<<a<<c<<c<<c<<" "<<" "<<" "<<" ";
        rlutil::locate(x+8, 16);
        cout<<" "<<c<<b<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<b<<c<<" "<<" ";
        rlutil::locate(x+8, 17);
        cout<<c<<a<<a<<c<<c<<b<<" "<<" "<<" "<<" "<<" "<<" "<<a<<c<<" ";
        rlutil::locate(x+8, 18);
        cout<<a<<c<<a<<c<<a<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<a<<" "<<b;
        rlutil::locate(x+8, 19);
        cout<<" "<<b<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<b<<" "<<" ";
        rlutil::locate(x+8, 20);
        cout<<" "<<" "<<" "<<b<<" "<<b<<" "<<" "<<" "<<b<<" "<<b<<" "<<" "<<" ";

        //oink
        rlutil::locate(x+1, 9);
        cout<<c<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<c;
        rlutil::locate(x+1, 10);
        cout<<a<<" "<<a<<b<<a<<" "<<a<<" "<<a<<c<<" "<<a<<" "<<a<<c<<b<<" "<<a;
        rlutil::locate(x+1, 11);
        cout<<a<<" "<<a<<c<<a<<" "<<a<<" "<<a<<" "<<b<<a<<" "<<a<<b<<c<<" "<<a;
        rlutil::locate(x+1, 12);
        cout<<b<<c<<c<<c<<c<<" "<<" "<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<b;
        rlutil::locate(x+1, 13);
        cout<<" "<<" "<<" "<<" "<<" "<<b<<c<<a;
        rlutil::locate(x+1, 14);
        cout<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<b;

        rlutil::msleep(300);//borra chanchito
        rlutil::locate(x+8, 15);
        cout<<"               ";
        rlutil::locate(x+8, 16);
        cout<<"               ";
        rlutil::locate(x+8, 17);
        cout<<"               ";
        rlutil::locate(x+8, 18);
        cout<<"               ";
        rlutil::locate(x+8, 19);
        cout<<"               ";
        rlutil::locate(x+8, 20);
        cout<<"               ";

        rlutil::locate(x+1, 9); //borra oink
        cout<<"                  ";
        rlutil::locate(x+1, 10);
        cout<<"                  ";
        rlutil::locate(x+1, 11);
        cout<<"                  ";
        rlutil::locate(x+1, 12);
        cout<<"                  ";
        rlutil::locate(x+1, 13);
        cout<<"                  ";
        rlutil::locate(x+1, 14);
        cout<<"                  ";

        rlutil::setColor(rlutil::LIGHTMAGENTA); //chanchito para abajo
        rlutil::locate(x+8, 16);
        cout<<" "<<" "<<c<<a<<c<<c<<a<<c<<c<<c<<c<<" "<<" "<<" "<<" ";
        rlutil::locate(x+8, 17);
        cout<<" "<<c<<b<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<b<<c<<" "<<" ";
        rlutil::locate(x+8, 18);
        cout<<c<<a<<a<<c<<c<<b<<" "<<" "<<" "<<" "<<" "<<" "<<a<<c<<b;
        rlutil::locate(x+8, 19);
        cout<<a<<c<<a<<c<<a<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<a<<" "<<" ";
        rlutil::locate(x+8, 20);
        cout<<" "<<b<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<b<<" "<<" ";

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(x, 22); //cartelito cargando
        cout<< "PRESIONE CUALQUIER TECLA" <<endl;

        rlutil::msleep(300);//borra chanchito
        rlutil::locate(x+8, 15);
        cout<<"               ";
        rlutil::locate(x+8, 16);
        cout<<"               ";
        rlutil::locate(x+8, 17);
        cout<<"               ";
        rlutil::locate(x+8, 18);
        cout<<"               ";
        rlutil::locate(x+8, 19);
        cout<<"               ";
        rlutil::locate(x+8, 20);
        cout<<"               ";

        rlutil::locate(x, 22); //cartelito cargando
        cout<< "                        " <<endl;

    }while(rlutil::nb_getch()==0);

    rlutil::cls();
}
