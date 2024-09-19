#ifndef ESTANCIAS_H_INCLUDED
#define ESTANCIAS_H_INCLUDED

void menuPrincipal(std::string nombres[]);
void tiraPrimero(std::string nombre[], bool &juegaPrimero);
void ronda(std::string nombres[], int acumTrufas[], int &contRondas, int contLanzamientos[], int acumTrufasRonda[], bool juegaPrimero, bool &hundido);

#endif // ESTANCIAS_H_INCLUDED
