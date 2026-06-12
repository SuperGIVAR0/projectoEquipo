#ifndef MEMBERS_H
#define MEMBERS_H

#include <string>

struct  Aventureros {
    std::string Nombre;
    int Contraseña;
    char Rango;
    std::string Raza;
    int Edad;
    std::string Clase;
    int Fuerza;
    int Agilidad;
    int Sabiduría;
    int Carisma;
};

struct Roster {
    std::string NombreDeRoster;
    Aventureros integrantes[5];
    int contador;
};

//Registra un aventurero al roster
void Registro(Roster &R);
//Imprime datos de los aventureros
void ImprimirDatos(Roster &A);
//Da de baja un aventurero del roster
void Baja(Roster &R);
//Busca entre los 5 aventureros si existe el de la busqueda e imprime
void BusquedaAventurero(Roster &R);
//Muestra el roster total
void ListadoRoster(Roster &R);

void members();

#endif // MEMBERS_H