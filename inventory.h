#ifndef GUILDEX_H
#define GUILDEX_H

struct Item
{
    int id;
    char nombre[50];
    int cantidad;
    char descripcion[50];
    float valor;
};

struct Adventurer
{
    int id;
    char nombre[50];
};

struct Quest
{
    int id;
    char nombre[50];
    int recompensa;
};

#endif