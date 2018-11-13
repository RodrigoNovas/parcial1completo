#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "utn.h"
int menu()
{
    int option;
    fflush(stdin);
    printf(" *****Menu*****\n"
           " 1. Alta Juego\n"
           " 2. Modificar Juego\n"
           " 3. Baja Juego\n"
           " 4. Mostrar Juegos\n"
           " 5. Alta Cliente\n"
           " 6. Modificar Cliente\n"
           " 7. Baja Cliente\n"
           " 8. Mostrar Clientes\n"
           " 9. Alta alquileres\n"
           " 10. Informes Totales\n"
           " 11. Salir\n"
           " Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    while(option < 0 || option > 11)
    {
        printf(" Por favor, ingrese una opcion del 1 al 11\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf(" *****Menu*****\n"
               " ****JUEGOS****\n"
               " 1. Alta Juego\n"
               " 2. Modificar Juego\n"
               " 3. Baja Juego\n"
               " 4. Mostrar Juegos\n"
               " ****CLIENTES****\n"
               " 5. Alta Cliente\n"
               " 6. Modificar Cliente\n"
               " 7. Baja Cliente\n"
               " 8. Mostrar Clientes\n"
               " ****ALQUILERES****\n"
               " 9. Alta alquileres\n"
               " 10. Salir\n"
               " Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &option);
    }
    return option;
}
