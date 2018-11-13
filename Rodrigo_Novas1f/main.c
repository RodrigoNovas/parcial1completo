#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "cliente.h"
#include "juegos.h"
#include "alquileres.h"
#include "informes.h"
#include "menu.h"
int main()
{
    eJuego listJuegos[MAXJUEGO];
    eCliente listClientes[MAXCLIENTE];
    eAlquiler listAlquileres[MAXALQUILERES];

    int option;

    int freeSlotJuego;
    int freeSlot;

    int auxIdJuego=0;
    char auxDescripcion[51];
    float auxImporte;

    int flagJuegos=0;
    int flagClientes=0;

    initJuego(listJuegos, MAXJUEGO);
    initCliente(listClientes, MAXCLIENTE);
    initAlquiler(listAlquileres, MAXALQUILERES);

    do
    {
        option=menu();

        switch(option)
        {
        case 1:
            flagJuegos++;
            freeSlotJuego=obtainFreeSlotJuego(listJuegos, MAXJUEGO);
            if (freeSlotJuego!=-1)
            {
                getString(" Ingrese descripcion:\n", auxDescripcion);
                fflush(stdin);

                auxImporte=getValidFloat(" Ingrese importe:\n", " Error, ingrese importe nuevamente (solo numero flotante):", 1, 1000000);
                fflush(stdin);
            }
            else
            {
                printf (" No hay espacio libre!\n");
                system ("pause");
                system ("cls");
            }
            addJuego(listJuegos, MAXJUEGO, auxIdJuego, auxDescripcion, auxImporte);
            break;
        case 2:
            if(flagJuegos!=0)
            {
                modifyJuegos(listJuegos, MAXJUEGO, auxIdJuego);
            }
            else
            {
                printf(" No existe ese ID de juego.\n");
                system ("pause");
            }
            system ("pause");
            system ("cls");
            break;
        case 3:
            if (flagJuegos!=0)
            {
                removeJuego(listJuegos, MAXJUEGO, auxIdJuego);
            }
            else
            {
                printf(" No existe ese ID de juego.\n");
                system ("pause");
            }
            break;
        case 4:
            if (flagJuegos!=0)
            {
                printJuegos(listJuegos, MAXJUEGO);
            }
            system ("pause");
            system ("cls");
            break;
        case 5:
            flagClientes++;
            freeSlot=obtainFreeSlot(listClientes, MAXCLIENTE);
            if (freeSlot!=-1)
            {

                addCliente(listClientes, MAXCLIENTE);
            }
            else
            {
                printf (" No hay espacio libre!\n");

            }
            system ("pause");
            system ("cls");
            break;
        case 6:
            if(flagClientes!=0)
            {
                modifyCliente(listClientes, MAXCLIENTE, freeSlot);//auxId);
            }
            else
            {
                printf(" No existe ese ID de cliente.\n");
                system ("pause");
            }
            break;
        case 7:
            if(flagClientes!=0)
            {
                removeCliente(listClientes, MAXCLIENTE, freeSlot);//auxId);
            }
            else
            {

                printf(" No existe ese ID de cliente.\n");
                system ("pause");
            }
            break;
        case 8:
            if(flagClientes!=0)
            {
                printClientes(listClientes, MAXCLIENTE);
                system ("pause");
                system ("cls");
            }
            else
            {
                printf(" No hay datos que mostrar\n");
                system ("pause");
            }
            break;
        case 9:
            addAlquiler(listAlquileres,MAXALQUILERES,listJuegos,MAXJUEGO,listClientes,MAXCLIENTE);
            system("pause");
            break;
        case 10:
            informes (listAlquileres,MAXALQUILERES,listJuegos,MAXJUEGO,listClientes,MAXCLIENTE);
            system("pause");
            break;
        case 11:
            printf (" Gracias por utilizar el sistema.\n");
            system("pause");
            break;
        default:
            printf (" Error. Ingrese nuevamente el comando del 1 al 11.");
            system("pause");
            break;
        }
        system("cls");
    }
    while (option!=11);
    return option;
}


