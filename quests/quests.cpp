#include <iostream>

struct Quest {
    std::string nombreQuest;
    std::string descripcion;
    bool completada;
};

void mostrarQuests(Quest misiones[]);

int main() {
    Quest misiones[10];

    misiones[0]={"Matar dragon","Traer la pezunna del dragon", false};
    misiones[1]={"Recolectar hierbas","Recolectar unicamente hierbas de color azul", false};
    misiones[2]={"Cazar","Traer especificamente pieles de osos", false};
    misiones[3]={"infiltracion","Rastrear ubicacion de nido de goblins", false};
    misiones[4]={"Escoltar","Llevar a comerciante al pueblo vecino sin que lo maten", false};
    misiones[5]={"Entrega","Lllevar un objeto al pueblo vecino", false};
    misiones[6]={"Defensa", "Defender zona de comercio de bandidos", false};
    misiones[7]={"Eliminacion","Elimina jefe de bandidos Toresk", false};
    misiones[8]={"Eliminacion con sigilo","Elimina jefe duende sin alertar a su manada", false};
    misiones[9]={"Investigacion", "Resuelve asesinato del Conde de MonteCristo", false};

    int opcion;
    std::cout<<"1. mostrar Quests"<<std::endl;
    std::cin>>opcion;

    switch (opcion) {
        case 1: {
            mostrarQuests(misiones);
            break;
        }
        default: {
            std::cout<<"Opcion no valida"<<std::endl;
        }
    }
    return 0;
}

void mostrarQuests(Quest misiones[]) {
    for (int i=0; i < 10; i++) {
        std::cout << "Quest: " << (*(misiones+i)).nombreQuest << std::endl;
        std::cout << "Descripcion: " << (*(misiones+i)).descripcion << std::endl;
        if ((*(misiones+i)).completada) {
            std::cout << "Estado: ocupada"<<"\n"<<std::endl;
        } else {
            std::cout << "Estado: desocupada"<<"\n"<<std::endl;
        }
    }
}