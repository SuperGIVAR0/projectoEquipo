#include <iostream>
#include "includeAllH.h"

int main() {
    int opcion = 0;

    do {
        std::cout << "1. Reporte general\n";
        std::cout << "2. Gestion de Quests\n";
        std::cout << "3. Gestion de Miembros\n";
        std::cout << "4. Gestion de Inventario\n";
        std::cout << "5. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout<<"No se como lo agregarias xd";
                break;

            case 2:
                quests();
                break;

            case 3:
                members();
                break;

            case 4:
                inventory();
                break;

            case 5:
                std::cout << "Saliendo...\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);
    return 0;
}
