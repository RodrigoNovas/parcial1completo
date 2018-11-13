#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "utn.h"

/** \brief Generates an unique ID for each alquiler
 *
 * \return unique ID
 *
 */
static int generateNextIdAlquiler ()
{
    static int idAlquiler=0;

    idAlquiler ++;

    return idAlquiler;
}

int initAlquiler (eAlquiler* listAlquileres, int len)
{
    int retorno=-1;
    int i;
    if(listAlquileres !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            listAlquileres[i].isEmpty=FREE;
        }
        retorno=0;
    }
    return retorno;
}

int obtainFreeSlotAlquiler(eAlquiler* listAlquileres, int len)
{
    int retorno=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(listAlquileres[i].isEmpty == FREE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int findAlquilerById(eAlquiler* listAlquileres, int len, int idAlquiler)
{
    int retorno=-1;
    int i;

    if(listAlquileres!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if (listAlquileres[i].idAlquiler == idAlquiler && listAlquileres[i].isEmpty==TAKEN)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


int addAlquiler(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos, int lenJuegos, eCliente* listClientes, int lenClientes)
{
    eAlquiler newAlquiler;

    int retorno=-1;
    int indexAuxOne=0;
    int indexAuxTwo=0;
    int freeSlot=obtainFreeSlotAlquiler(listAlquileres, lenAlquileres);

    if(listAlquileres!=NULL && listClientes!=NULL && listJuegos!=NULL)
    {
        if(freeSlot==-1)
        {
            printf(" No hay espacio libre");
        }
        if(freeSlot!=-1)
        {
            newAlquiler.idJuego=addJuegoById(listJuegos, lenJuegos);

            if(newAlquiler.idJuego==-1)
            {
                printf(" No existe ese ID de juego.\n");
            }
            else
            {
                newAlquiler.id=addClienteById(listClientes, lenClientes);
                if(newAlquiler.id==-1)
                {
                    printf(" No existe ese ID de cliente.\n");
                    system("pause");
                }
                else
                {
                    newAlquiler.fechaIngreso.dia= getValidInt(" Ingrese dia: "," Error, dia no valido.", 1, 31);
                    newAlquiler.fechaIngreso.mes = getValidInt(" Ingrese mes: "," Error, mes no valido.", 1, 12);
                    newAlquiler.fechaIngreso.anio = getValidInt(" Ingrese anio: "," Error, anio no valido.", 1990, 2018);
                    newAlquiler.id =generateNextIdAlquiler();

                    newAlquiler.isEmpty=0;

                    listAlquileres[freeSlot] = newAlquiler;

                    printf(" Se alquilo el juego: \n");

                    indexAuxOne = findJuegoById(listJuegos, lenJuegos, newAlquiler.idJuego);
                    printJuego(listJuegos, indexAuxOne);

                    printf(" El cliente que lo alquilo fue: \n");

                    indexAuxTwo = findClienteById(listClientes, lenClientes, newAlquiler.id);
                    printCliente(listClientes, indexAuxTwo);

                    printf(" En la fecha: %d/%d/%d\n", newAlquiler.fechaIngreso.dia,newAlquiler.fechaIngreso.mes, newAlquiler.fechaIngreso.anio);

                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int addJuegoById(eJuego* listJuegos, int len)
{
    int retorno=-1;
    int i;
    int idJuego;

    if(listJuegos!=NULL)
    {
        printJuegos(listJuegos, len);
        printf (" Ingrese el ID de juego que desea alquilar: \n");
        scanf ("%d", &idJuego);
        for(i=0; i<len; i++)
        {
            if (listJuegos[i].idJuego == idJuego && listJuegos[i].isEmpty==TAKEN)
            {
                retorno=idJuego;
                break;
                retorno=0;
            }
        }
    }
    return retorno;
}

int addClienteById(eCliente* listCliente, int len)
{
    int retorno=-1;
    int i;
    int id;

    if(listCliente!=NULL)
    {
        printClientes(listCliente, len);
        printf (" Ingrese el ID del cliente que lo alquilo: \n");
        scanf ("%d", &id);
        for(i=0; i<len; i++)
        {
            if (listCliente[i].id == id && listCliente[i].isEmpty==TAKEN)
            {
                retorno=id;
                break;
                retorno=0;
            }
        }
    }
    return retorno;
}

