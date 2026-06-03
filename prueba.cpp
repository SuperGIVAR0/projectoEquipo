#include <iostream>

void generarReporteGeneral();
void limpiarPantalla();

int main() {
    int opcion = 0;

     {
        limpiarPantalla();
        std::cout << "====================================================\n";
        std::cout << "        SISTEMA DE GESTION DE GREMIO v1.0          \n";
        std::cout << "====================================================\n";
        std::cout << " [1] REPORTE GENERAL DEL GREMIO\n";
        std::cout << " [2] SALIR DEL SISTEMA\n";
        std::cout << "====================================================\n";
        std::cout << " Seleccione una opcion: ";


        if (!(std::cin >> opcion)) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            opcion = 0;
        }

        switch (opcion) {
            case 1:
                generarReporteGeneral();
                break;
            case 2:
                std::cout << "\n Guardando datos en el pergamino... ¡Buen viaje, Maestro de Gremio!\n";
                break;
            default:
                std::cout << "\n  Opcion no valida. Presione Enter para intentar de nuevo...";
                std::cin.ignore();
                std::cin.get();
                break;
        }

    } while (opcion != 2);

    return 0;
}


void limpiarPantalla() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void generarReporteGeneral() {
    limpiarPantalla();
    std::cout << "====================================================\n";
    std::cout << "             ESTADO ACTUAL DEL GREMIO               \n";
    std::cout << "====================================================\n";

    std::cout << " >> RESUMEN DE AVENTUREROS <<\n";
    std::cout << "    - Total de Miembros Activos: 24\n";
    std::cout << "    - Rangos: [S: 1] [A: 3] [B: 5] [C: 10] [D/E: 5]\n";
    std::cout << "----------------------------------------------------\n";

    std::cout << " >> ESTADO DE LAS MISIONES <<\n";
    std::cout << "    - Disponibles en Tablon : 7\n";
    std::cout << "    - En Progreso           : 3\n";
    std::cout << "    - Completadas con Exito : 142\n";
    std::cout << "----------------------------------------------------\n";

    std::cout << " >> BALANCE DE INVENTARIO <<\n";
    std::cout << "    - Total de Items en Fondo : 56 unidades\n";
    std::cout << "    - Oro Total del Gremio    : 15450 monedas\n";
    std::cout << "====================================================\n";

    std::cout << "\n Presione Enter para regresar al Menu Principal...";
    std::cin.ignore();
    std::cin.get();
}