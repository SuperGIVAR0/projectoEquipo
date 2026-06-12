#include <iostream>
#include "guildex.h" // ¡Aquí conectas tu archivo maestro!

using namespace std;

int main() {
    int opcion;

    do {
        // --- Interfaz del Menú ---
        cout << "\n====================================\n";
        cout << "       SISTEMA GUILDEX v1.0         \n";
        cout << "====================================\n";
        cout << "1. Gestionar Miembros\n";
        cout << "2. Gestionar Inventario\n";
        cout << "3. Gestionar Misiones\n";
        cout << "4. Salir del Sistema\n";
        cout << "====================================\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        // --- Navegación ---
        switch(opcion) {
            case 1:
                cout << "\nAbriendo modulo de Miembros...\n";
                // members(); <-- Aquí llamarás a la función de Nahbi después
                break;
            case 2:
                cout << "\nAbriendo modulo de Inventario...\n";
                // inventory(); <-- Aquí llamarás a la función de Santiago después
                break;
            case 3:
                cout << "\nAbriendo modulo de Misiones...\n";
                // quests(); <-- Aquí llamarás a la función de Gilberto después
                break;
            case 4:
                cout << "\nCerrando el sistema Guildex. ¡Hasta pronto!\n";
                break;
            default:
                cout << "\nOpcion no valida. Intenta de nuevo.\n";
        }

    } while(opcion != 4); // El ciclo se repite hasta que elijan salir (4)

    return 0;
}