//Members
#include <iostream>
#include <string>
#include <windows.h>


struct  Aventureros {
    std::string Nombre;
    std::string Contrasenia;
    char Rango;
    std::string Raza;
    int Edad;
    std::string Clase;
    int Fuerza;
    int Agilidad;
    int Sabiduria;
    int Carisma;
};

struct Roster {
    std::string NombreDeRoster;
    Aventureros A1;
    Aventureros A2;
    Aventureros A3;
    Aventureros A4;
    Aventureros A5;
};

/*void Registro(Aventureros &A) {

}*/


int main() {
    SetConsoleOutputCP(65001);
int op;

    do{
        std::cout<<"⦿ Bienvenido a Guildex ⦿ \n\n 1 ≡ Registro de Usuario \n 2 ≡ Baja de Usuario \n 3 ≡ Busqueda de Usuario \n 4 ≡ Listado de Roster \n 5 ≡ Salir "<<std::endl;
std::cin>> op;
    switch (op) {
        case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            std::cout << "\n\nGracias por usar la Gestion de Roster de Guildex"<<std::endl;
            break;
        default:
            std::cout << "\nOpcion no valida vuelva a intentar"<<std::endl;
            break;
    }
}while(op!=5);



    return 0;
}