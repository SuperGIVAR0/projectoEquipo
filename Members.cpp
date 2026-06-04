#include <iostream>
#include <string>
#include <windows.h>


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

void Registro(Roster &R);
void ImprimirDatos(Roster &A);
void Baja(Roster &R);
void BusquedaAventurero(Roster &R);


int main() {
    SetConsoleOutputCP(65001);
    int op;
    Roster R;
    R.contador = 0;
    R.NombreDeRoster = "Guildex";

    do{
        std::cout << "⦿ Bienvenido a Guildex - Menú Aventureros ⦿ \n\n 1 ≡ Registro de Usuario \n 2 ≡ Baja de Usuario \n 3 ≡ Búsqueda de Usuario \n 4 ≡ Listado de Roster \n 5 ≡ Salir " << std::endl;
std::cin>> op;
    switch (op) {
        case 1:
            Registro(R);
            break;
            case 2:
            Baja(R);
            break;
            case 3:
            BusquedaAventurero(R);
            break;
            case 4:
            //falta hacer funcion
            break;
            case 5:
            std::cout << "\n\nGracias por usar la Gestión de Roster de Guildex" << std::endl;
            break;
        default:
            std::cout << "\nOpción no válida, vuelva a intentar." << std::endl;
            break;
    }
}while(op!=5);



    return 0;
}

void Registro(Roster &R) {

    if (R.contador >= 5) {
        std::cout << "\nEl roster está lleno (máximo 5 aventureros)." << std::endl;
        return;
    }

    std::cout << "\n\n✎ REGISTRO DE AVENTUREROS \n\n" << std::endl;

    int i = R.contador;
        std::cout<<"\n  Nombre : "<<std::endl;
        std::cin>>R.integrantes[i].Nombre;

        std::cout<<"\n Contraseña : "<<std::endl;
        std::cin>>R.integrantes[i].Contraseña;

    std::cout<<"\n Rango : "<<std::endl;
        std::cin>>R.integrantes[i].Rango;

    std::cout<<"\n Raza : "<<std::endl;
        std::cin>>R.integrantes[i].Raza;

    std::cout<<"\n Edad : "<<std::endl;
        std::cin>>R.integrantes[i].Edad;

    std::cout<<"\n Clase : "<<std::endl;
        std::cin>>R.integrantes[i].Clase;

    std::cout<<"\n Fuerza : "<<std::endl;
        std::cin>>R.integrantes[i].Fuerza;

    std::cout<<"\n Agilidad : "<<std::endl;
        std::cin>>R.integrantes[i].Agilidad;

    std::cout<<"\n Sabiduría : "<<std::endl;
        std::cin>>R.integrantes[i].Sabiduría;

    std::cout<<"\n Carisma : "<<std::endl;
        std::cin>>R.integrantes[i].Carisma;

    std::cout<<"\n \n"<<std::endl;

        R.contador++;

    std::cout << "\n✔ Aventurero registrado. Total en roster: " << R.contador << "/5\n";
    }

void ImprimirDatos(Aventureros &A) {
    std::cout<<"\n \n"<<std::endl;
    std::cout<<"⌦ .｡.:*♡ DATOS DEL AVENTURERO \n"<<std::endl;

    std::cout << "\n  Nombre     : " << A.Nombre;
    std::cout << "\n  Contraseña: " << A.Contraseña;
    std::cout << "\n  Rango      : " << A.Rango;
    std::cout << "\n  Raza       : " << A.Raza;
    std::cout << "\n  Edad       : " << A.Edad;
    std::cout << "\n  Clase      : " << A.Clase;
    std::cout << "\n  Fuerza     : " << A.Fuerza;
    std::cout << "\n  Agilidad   : " << A.Agilidad;
    std::cout << "\n  Sabiduría  : " << A.Sabiduría;
    std::cout << "\n  Carisma    : " << A.Carisma;
    std::cout<<"\n \n"<<std::endl;
}

void Baja(Roster &R) {
    std::string Usuario;
    int password;
    std::cout<<"\n \n"<<std::endl;
    std::cout<<"¡! ❞ BORRAR DATOS DEL AVENTURERO ❞ ¡!\n"<<std::endl;
    std::cout<<"Ingrese el nombre del usuario: "<<std::endl;
    std::cin>>Usuario;
    bool encontrado = false;
    for (int i = 0; i < R.contador; i++) {

 if (Usuario == R.integrantes[i].Nombre) {
        std::cout<<"\n Ingrese Contraseña de "<<Usuario<<std::endl;
        std::cin>>password;
         encontrado = true;


        if (password == R.integrantes[i].Contraseña) {
            R.integrantes[i] = R.integrantes[R.contador - 1];
            R.contador--;
            std::cout<<"\n Contraseña confirmada borrando usuario..."<<std::endl;

        }
        else {
            std::cout << "Contraseña incorrecta, no se borrarán los datos."<<std::endl;
            std::cout<<"\n \n"<<std::endl;
        }
     break;
    }
   if (encontrado == false) {
        std::cout<<"Usuario no encontrado."<<std::endl;
    }
    std::cout<<"\n \n"<<std::endl;
    }


}

void BusquedaAventurero(Roster &R) {
    std::cout<<"\n \n"<<std::endl;
    std::string Usuario;
    std::cout<<"ೃ‧₊› BUSCAR AVENTURERO \n"<<std::endl;
    std::cout<<"Ingrese el Nombre de Usuario: "<<std::endl;
    std::cin>>Usuario;
    bool encontrado = false;
    for (int i = 0; i < R.contador; i++) {
        if (Usuario == R.integrantes[i].Nombre) {

            ImprimirDatos(R.integrantes[i]);
            encontrado = true;
            break;
        }
        if (encontrado == false) {
        std::cout<<"Usuario no encontrado."<<std::endl;
    }
    }

    std::cout<<"\n \n"<<std::endl;
}