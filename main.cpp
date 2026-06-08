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


int main() {
    //Le dice a la consola que se muestren los caracteres bonitos
    SetConsoleOutputCP(65001);
    int op;

    //Se inicia Roster dandole el nombre de guildex
    Roster R;
    R.contador = 0;
    R.NombreDeRoster = "Guildex";

    do{
        std::cout << "⦿ Bienvenido a Guildex - Menú Aventureros ⦿ \n\n 1 ≡ Registro de Usuario \n 2 ≡ Baja de Usuario \n 3 ≡ Búsqueda de Usuario \n 4 ≡ Listado de Roster \n 5 ≡ Salir " << std::endl;
std::cin>> op;
        std::cin.ignore();
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
            ListadoRoster(R);
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

//PRIMERA OPCION DEL MENU
void Registro(Roster &R) {

    //if si el roster esta lleno no deja ingresar mas aventureros
    if (R.contador >= 5) {
        std::cout << "\nEl roster está lleno (máximo 5 aventureros)." << std::endl;
        return;
    }

    std::cout << "\n\n✎ REGISTRO DE AVENTUREROS \n\n" << std::endl;

    //i = al contador del roster para asignarle al aventurero el numero disponible del arreglo
    int i = R.contador;

    //Se rellenan los valores del aventurero
        std::cout<<"\n  Nombre : "<<std::endl;
     std::getline(std::cin , R.integrantes[i].Nombre);

        std::cout<<"\n Contraseña : "<<std::endl;
        std::cin>>R.integrantes[i].Contraseña;
    std::cin.ignore();

    std::cout<<"\n Rango : "<<std::endl;
        std::cin>>R.integrantes[i].Rango;
    std::cin.ignore();

    std::cout<<"\n Raza : "<<std::endl;
      std::getline( std::cin , R.integrantes[i].Raza);

    std::cout<<"\n Edad : "<<std::endl;
        std::cin>>R.integrantes[i].Edad;
    std::cin.ignore();

    std::cout<<"\n Clase : "<<std::endl;
       std::getline(  std::cin,R.integrantes[i].Clase);

    std::cout<<"\n Fuerza : "<<std::endl;
        std::cin>>R.integrantes[i].Fuerza;
    std::cin.ignore();

    std::cout<<"\n Agilidad : "<<std::endl;
        std::cin>>R.integrantes[i].Agilidad;
    std::cin.ignore();

    std::cout<<"\n Sabiduría : "<<std::endl;
        std::cin>>R.integrantes[i].Sabiduría;
    std::cin.ignore();

    std::cout<<"\n Carisma : "<<std::endl;
        std::cin>>R.integrantes[i].Carisma;

    std::cout<<"\n \n"<<std::endl;

    //Se le suma al contador
        R.contador++;

    //Se imprime en pantalla el numero de aventureros en el roster al momento
    std::cout << "\n✔ Aventurero registrado. Total en roster: " << R.contador << "/5\n";
    }

//Imprime en pantalla todos los campos de un aventurero
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

//SEGUNDA OPCION DEL MENU
void Baja(Roster &R) {
    std::string Usuario;
    int password;
    std::cout<<"\n \n"<<std::endl;
    std::cout<<"¡! ❞ BORRAR DATOS DEL AVENTURERO ❞ ¡!\n"<<std::endl;
    std::cout<<"Ingrese el nombre del usuario: "<<std::endl;
    std::getline( std::cin , Usuario);
    bool encontrado = false;
    //Va por todos los usuarios en el contador
    for (int i = 0; i < R.contador; i++) {
//Si encuentra que un usuario coincide en el roster le va a pedir su contrasenia
 if (Usuario == R.integrantes[i].Nombre) {
        std::cout<<"\n Ingrese Contraseña de "<<Usuario<<std::endl;
        std::cin>>password;
         encontrado = true;

//Si la contrasenia es correcta se borra el aventurero y se resta del contador del roster
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

    }
if (encontrado == false) {
        std::cout<<"Usuario no encontrado."<<std::endl;
    }
    std::cout<<"\n \n"<<std::endl;

}

//TERCERA OPCION DEL MENU
void BusquedaAventurero(Roster &R) {
    std::cout<<"\n \n"<<std::endl;
    std::string Usuario;
    std::cout<<"ೃ‧₊› BUSCAR AVENTURERO \n"<<std::endl;
    std::cout<<"Ingrese el Nombre de Usuario: "<<std::endl;
  std::getline(   std::cin,Usuario);
    bool encontrado = false;
    for (int i = 0; i < R.contador; i++) {
        if (Usuario == R.integrantes[i].Nombre) {

            ImprimirDatos(R.integrantes[i]);
            encontrado = true;
            break;
        }

    }
if (encontrado == false) {
        std::cout<<"Usuario no encontrado."<<std::endl;
    }
    std::cout<<"\n \n"<<std::endl;
}

//CUARTA OPCION DEL MENU
void ListadoRoster(Roster &R) {

    std::cout<<"\n\n✥ LISTADO DE ROSTER ✥\n\n"<<std::endl;

    std::cout<<"Roster: "<< R.NombreDeRoster <<std::endl;
    std::cout<<"\n Integrantes: "<< R.contador << "/5 \n" <<std::endl;

    if (R.contador == 0) {
       std::cout<<"No hay integrantes en el Roster\n"<<std::endl;
    }

    //Usa el contador para ir por cada uno de los integrantes resgistrados en el roster al momento
    for (int i = 0; i < R.contador; i++) {
        std::cout<<"\n ["<< i+1 <<"]"<<std::endl;
         ImprimirDatos(R.integrantes[i]);
    }


}
