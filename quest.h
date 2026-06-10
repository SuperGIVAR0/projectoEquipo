//
// Created by gilbe on 6/10/2026.
//

#ifndef PROJECTOEQUIPO_QUEST_H
#define PROJECTOEQUIPO_QUEST_H
#include "string"

struct Quest {
    std::string nombreQuest;
    std::string descripcion;
    bool completada;
    int dificultad;
};

void mostrarQuests(Quest misiones[]);
void completarQuests(Quest misiones[], std::string*& historial, int& cantidadHistorial);
void mostrarHistorial(std::string historial[], int cantidadHistorial);
void quests();

#endif //PROJECTOEQUIPO_QUEST_H
