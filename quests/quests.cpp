#include <iostream>

struct Quest {
    std::string nombreQuest;
    std::string descripcion;
    bool completada;
};
void mostrarQuests(Quest misiones[]);
void completarQuests(Quest misiones[],std::string*& historial, int& cantidadHistorial);
void mostrarHistorial(std::string historial[], int cantidadHistorial);

int main() {
    Quest misiones[10];

    misiones[0]={"0.Matar dragon","Traer la pezunna del dragon", false};
    misiones[1]={"1.Recolectar hierbas","Recolectar unicamente hierbas de color azul", false};
    misiones[2]={"2.Cazar","Traer especificamente pieles de osos", false};
    misiones[3]={"3.infiltracion","Rastrear ubicacion de nido de goblins", false};
    misiones[4]={"4.Escoltar","Llevar a comerciante al pueblo vecino sin que lo maten", false};
    misiones[5]={"5.Entrega","Lllevar un objeto al pueblo vecino", false};
    misiones[6]={"6.Defensa", "Defender zona de comercio de bandidos", false};
    misiones[7]={"7.Eliminacion","Elimina jefe de bandidos Toresk", false};
    misiones[8]={"8.Eliminacion con sigilo","Elimina jefe duende sin alertar a su manada", false};
    misiones[9]={"9.Investigacion", "Resuelve asesinato del Conde de MonteCristo", false};

    std::string* historial = nullptr;
    int cantidadHistorial = 0;

    int opcion = 0;
    while (opcion != 4) {
        std::cout<<"1. mostrar Quests"<<std::endl;
        std::cout<<"2. Elegir mision"<<std::endl;
        std::cout<<"3. Mostrar historial"<<std::endl;
        std::cout<<"4. Salir de quests\n"<<std::endl;
        std::cin>>opcion;

        switch (opcion) {
            case 1: {
                mostrarQuests(misiones);
                break;
            }
            case 2: {
                mostrarQuests(misiones);
                completarQuests(misiones, historial, cantidadHistorial);
                mostrarQuests(misiones);
                break;
            }
            case 3: {
                mostrarHistorial(historial,cantidadHistorial);
                break;
            }
            case 4: {
                std::cout<<"Saliendo de quests"<<std::endl;
                break;
            }
            default: {
                std::cout<<"Opcion no valida"<<std::endl;
            }
        }
    }

    delete[] historial;
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
void completarQuests(Quest misiones[],std::string*& historial, int& cantidadHistorial) {
    int indice;
    int opcion;

    std::cout << "Indice de la mision: ";
    std::cin >> indice;

    if (indice >= 0 && indice < 10) {
        std::cout << "1. Ocupar\n2. Desocupar\n";
        std::cin >> opcion;

        Quest* quest = misiones + indice;

        if (opcion == 1) {
            (*quest).completada = true;

            std::string* nuevoHistorial = new std::string[cantidadHistorial + 1];

            for (int i = 0; i < cantidadHistorial; i++) {
                nuevoHistorial[i] = historial[i];
            }

            nuevoHistorial[cantidadHistorial] = (*quest).nombreQuest;

            delete[] historial;

            historial = nuevoHistorial;

            cantidadHistorial++;
        }
        else if (opcion == 2) {
            (*quest).completada = false;
        }
        else {
            std::cout << "Opcion invalida\n";
        }
    }
    else {
        std::cout << "Indice invalido\n";
    }
}

void mostrarHistorial(std::string historial[], int cantidadHistorial) {
    std::cout<<"Historial de quest anteriormente activadas"<<std::endl;
    if (cantidadHistorial == 0) {
        std::cout<<"No hay ningun historial registrado"<<std::endl;
    }
    else {
        for (int i = 0; i < cantidadHistorial; i++) {
            std::cout<<historial[i]<<std::endl;
        }
    }
}