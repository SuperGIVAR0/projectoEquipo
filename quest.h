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

void quests();

#endif //PROJECTOEQUIPO_QUEST_H
