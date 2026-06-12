#ifndef PROYECTO_GUILDEX_H
#define PROYECTO_GUILDEX_H
//--------------------------INVENTARIO-------------------------
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

struct QuestInventario
{
    int id;
    char nombre[50];
    int recompensa;
};

void inventory();

//--------------------------MIEMBROS-------------------------

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
void ImprimirDatos(Aventureros &A);
//Da de baja un aventurero del roster
void Baja(Roster &R);
//Busca entre los 5 aventureros si existe el de la busqueda e imprime
void BusquedaAventurero(Roster &R);
//Muestra el roster total
void ListadoRoster(Roster &R);

void members();
//--------------------------MISIONES-------------------------
struct Quest {
    std::string nombreQuest;
    std::string descripcion;
    bool completada;
    int dificultad;
};
void quests();

#endif //PROYECTO_GUILDEX_H
