#include <iostream>
#include <string>
#include "quest.h"


//Basicamente te hace un recorrido de todas las quests
void mostrarQuests(Quest misiones[]) {
    for (int i=0; i < 10; i++) {
        std::cout << "Quest: " << (*(misiones+i)).nombreQuest << std::endl;
        std::cout << "Descripcion: " << (*(misiones+i)).descripcion << std::endl;
        std::cout << "Nivel de mision: " << (*(misiones+i)).dificultad <<std::endl;
        if ((*(misiones+i)).completada) {
            std::cout << "Estado: ocupada"<<"\n"<<std::endl;
        } else {
            std::cout << "Estado: desocupada"<<"\n"<<std::endl;
        }
    }
}

//Una vez mostrada las quests, les puse un indice a lado, para que eliga si esta ocupada o desocupada
void completarQuests(Quest misiones[],std::string*& historial, int& cantidadHistorial) {
    int indice;
    int opcion;

    std::cout << "Indice de la mision: ";
    std::cin >> indice;

    if (indice >= 0 && indice < 10) {
        std::cout << "1. Ocupar\n2. Desocupar\n";
        std::cin >> opcion;

        //aqui va el puntero directo a la mision que hayas seleccionado en indice
        Quest* quest = misiones + indice;


        //Si elige la opcion uno que es la de ocupada, pues la hara true, por eso en todas les puse false al principio
        if (opcion == 1) {
            (*quest).completada = true;


            //al momento de poner new, se agrega al heap en vez de al stack
            std::string* nuevoHistorial = new std::string[cantidadHistorial + 1];

            //actualiza el historial
            for (int i = 0; i < cantidadHistorial; i++) {
                nuevoHistorial[i] = historial[i];
            }

            //lo que guarda es el nombre de la mision
            nuevoHistorial[cantidadHistorial] = (*quest).nombreQuest;


            //libera memoria
            delete[] historial;


            //lo actualiza
            historial = nuevoHistorial;

            //aumenta historial de 0 a 1 y consecutivamente
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

void quests() {

    //Tamanno de misiones que hay
    Quest misiones[10];

    misiones[0]={"0.Matar dragon","Traer la pezunna del dragon", false, 10};
    misiones[1]={"1.Recolectar hierbas","Recolectar unicamente hierbas de color azul", false, 1};
    misiones[2]={"2.Cazar","Traer especificamente pieles de osos", false, 3};
    misiones[3]={"3.infiltracion","Rastrear ubicacion de nido de goblins", false, 6};
    misiones[4]={"4.Escoltar","Llevar a comerciante al pueblo vecino sin que lo maten", false, 5};
    misiones[5]={"5.Entrega","Lllevar un objeto al pueblo vecino", false, 4};
    misiones[6]={"6.Defensa", "Defender zona de comercio de bandidos", false, 5};
    misiones[7]={"7.Eliminacion","Elimina jefe de bandidos Toresk", false, 8};
    misiones[8]={"8.Eliminacion con sigilo","Elimina jefe duende sin alertar a su manada", false, 7};
    misiones[9]={"9.Investigacion", "Resuelve asesinato del Conde de MonteCristo", false, 3};

    //Se ocupan para poder guardar el historial, puse a nullptr, porque basicamente no se utiliza todavia, sino hasta que
    //jala la funcion y le puse 0 pa que no apunte a otro lugar en mi ram.
    std::string* historial = nullptr;
    int cantidadHistorial = 0;


    //Listado de cosas que puedes hacer
    int opcion = 0;
    while (opcion != 4) {
        std::cout<<"1. mostrar Quests"<<std::endl;
        std::cout<<"2. Elegir mision o desocupar mision"<<std::endl;
        std::cout<<"3. Mostrar historial"<<std::endl;
        std::cout<<"4. Salir de quests\n"<<std::endl;
        std::cin>>opcion;

        //Switch con funciones adentro de lo que pueden hacer
        switch (opcion) {
            case 1: {
                mostrarQuests(misiones);
                break;
            }
            case 2: {

                //Esta otra vez esta funcion por si no eligio la opcion 1
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
}