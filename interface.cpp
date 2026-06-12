// Modulo 4  Menu principal e integracion de modulos
// Creado por Emi 6/11/2026
// Aun no sabemos como hacer que conecte la informacion de ningun .cpp
#include <iostream>
#include "includeAllH.h"


//  Reporte general

void reporteGeneral(Roster& roster, Item* inventario, int cantidadItems, Quest misiones[])
{
    std::cout << "\n";
    std::cout << "       REPORTE GENERAL - GUILDEX      \n";

    std::cout << "\n MIEMBROS DEL GREMIO\n";
    std::cout << "  Roster       : " << roster.NombreDeRoster << "\n";
    std::cout << "  Registrados  : " << roster.contador << " / 5\n";

    if (roster.contador > 0)
    {
        std::cout << "  Integrantes  :\n";
        for (int i = 0; i < roster.contador; i++)
        {
            std::cout << "    [" << i + 1 << "] "
                      << roster.integrantes[i].Nombre
                      << "  |  Rango: " << roster.integrantes[i].Rango
                      << "  |  Clase: " << roster.integrantes[i].Clase
                      << "\n";
        }
    }
    else
    {
        std::cout << "  (Sin integrantes registrados)\n";
    }


    std::cout << "\n INVENTARIO\n";
    std::cout << "  Items registrados : " << cantidadItems << "\n";

    if (cantidadItems > 0)
    {
        float valorTotal = 0;
        for (int i = 0; i < cantidadItems; i++)
        {
            valorTotal += inventario[i].cantidad * inventario[i].valor;
            std::cout << "    - " << inventario[i].nombre
                      << "  x" << inventario[i].cantidad
                      << "  (val. unit.: " << inventario[i].valor << ")\n";
        }
        std::cout << "  Valor total       : " << valorTotal << " oro\n";
    }
    else
    {
        std::cout << "  (Inventario vacio)\n";
    }

    std::cout << "\n QUESTS\n";

    int ocupadas   = 0;
    int libres     = 0;

    for (int i = 0; i < 10; i++)
    {
        if (misiones[i].completada)
            ocupadas++;
        else
            libres++;
    }

    std::cout << "  Total de quests : 10\n";
    std::cout << "  Ocupadas        : " << ocupadas << "\n";
    std::cout << "  Disponibles     : " << libres   << "\n";

    if (ocupadas > 0)
    {
        std::cout << "  En curso        :\n";
        for (int i = 0; i < 10; i++)
        {
            if (misiones[i].completada)
            {
                std::cout << "    - " << misiones[i].nombreQuest
                          << "  (dificultad: " << misiones[i].dificultad << ")\n";
            }
        }
    }

}

void menuPrincipal()
{

    Roster roster;
    roster.contador      = 0;
    roster.NombreDeRoster = "Guildex";

    Item* inventarioReporte   = nullptr;
    int   cantidadItemsReporte = 0;

    // Quests
    Quest misionesReporte[10] = {
        {"0.Matar dragon",           "Traer la pezunna del dragon",                     false, 10},
        {"1.Recolectar hierbas",     "Recolectar unicamente hierbas de color azul",     false,  1},
        {"2.Cazar",                  "Traer especificamente pieles de osos",             false,  3},
        {"3.Infiltracion",           "Rastrear ubicacion de nido de goblins",           false,  6},
        {"4.Escoltar",               "Llevar a comerciante al pueblo vecino",           false,  5},
        {"5.Entrega",                "Llevar un objeto al pueblo vecino",               false,  4},
        {"6.Defensa",                "Defender zona de comercio de bandidos",           false,  5},
        {"7.Eliminacion",            "Elimina jefe de bandidos Toresk",                false,  8},
        {"8.Eliminacion con sigilo", "Elimina jefe duende sin alertar a su manada",    false,  7},
        {"9.Investigacion",          "Resuelve asesinato del Conde de MonteCristo",    false,  3}
    };

    int opcion = 0;

    do
    {
        std::cout << "\n";
        std::cout << "          GUILDEX  -  INICIO          \n";
        std::cout << "  1. Reporte general                  \n";
        std::cout << "  2. Gestion de Quests                \n";
        std::cout << "  3. Gestion de Miembros              \n";
        std::cout << "  4. Gestion de Inventario            \n";
        std::cout << "  5. Salir                            \n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion)
        {
            case 1:
                reporteGeneral(roster, inventarioReporte, cantidadItemsReporte, misionesReporte);
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
                std::cout << "\nHasta luego, aventurero.\n";
                break;

            default:
                std::cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 5);

}
