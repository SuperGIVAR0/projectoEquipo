#ifndef PROYECTO_GUILDEX_H
#define PROYECTO_GUILDEX_H

#include <string>



struct Adventurer {
    int id;
    char name[50];
    char adventurer_class[50];
    int level;
    char rank;
    int active;

    // Stats agregados del trabajo de Nahbi
    int fuerza;
    int agilidad;
    int sabiduria;
    int carisma;
};

struct Roster {
    char nombreDeRoster[50];
    Adventurer integrantes[5];
    int contador;
};

struct Item {
    int id;
    char name[50];
    char description[100];
    int quantity;
    double value;
};

struct Quest {
    int id;
    char title[50];
    char description[100];
    int difficulty;
    int reward;
    int assignee_id;
    int completed;
};

// ==========================================
// 2. PROTOTIPOS DE FUNCIONES
// ==========================================

// --- Módulo 1: Miembros (Nahbi) ---
void Registro(Roster &R);
void ImprimirDatos(Roster &A);
void Baja(Roster &R);
void BusquedaAventurero(Roster &R);
void ListadoRoster(Roster &R);
void members();

// --- Módulo 2: Inventario (Santiago) ---
void inventory();
int buscarItem(Item* inventario, int cantidadItems, int idBuscado);
void mostrarInventario(Item* inventario, int cantidadItems);

// --- Módulo 3: Misiones (Gilberto) ---
void mostrarQuests(Quest misiones[]);
void completarQuests(Quest misiones[], std::string*& historial, int& cantidadHistorial);
void mostrarHistorial(std::string historial[], int cantidadHistorial);
void quests();

#endif //PROYECTO_GUILDEX_H