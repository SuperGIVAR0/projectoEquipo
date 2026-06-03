#ifndef GUILDEX_H
#define GUILDEX_H

struct Adventurer {
    int  id;
    char name;
    char adventurer_class;
    int  level;
    char rank;
    int  active;
};

struct Item {
    int  id;
    char name;
    char description;
    int  quantity;
    double value;
};

struct Quest {
    int  id;
    char title;
    char description;
    int  difficulty;
    int  reward;
    int  assignee_id;
    int  completed;
};
#endif
