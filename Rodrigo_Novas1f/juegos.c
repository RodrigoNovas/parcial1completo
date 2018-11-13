#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "utn.h"

static int generateNextIdJuego ()
{
    static int idJuego=1;

    idJuego++;

    return idJuego;
}



int initJuego(eJuego* listJuegos, int len)
{
    int retorno=-1;
    int i;
    if(listJuegos !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            listJuegos[i].isEmpty=FREE;
        }
        retorno=0;
    }
    return retorno;
}

int obtainFreeSlotJuego(eJuego* listJuegos, int len)
{   int i;
    int retorno=-1;

    for( i=0; i<len; i++)
    {
        if(listJuegos[i].isEmpty == FREE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int addJuego(eJuego* listJuegos, int len, int idJuego, char* descripcion, float importe)
{
    int retorno=-1;
    int auxIdJuego = 1;
    int indexJuegosIsEmpty=obtainFreeSlotJuego(listJuegos, len);
    int indexJuegosId=findJuegoById(listJuegos, len, auxIdJuego);

    if(listJuegos!= NULL)
    {
        if (descripcion!=NULL)
        {
            if (indexJuegosIsEmpty!=-1)
            {
                if (listJuegos[indexJuegosId].isEmpty==TAKEN)
                {
                    auxIdJuego=generateNextIdJuego();
                }
                listJuegos[indexJuegosIsEmpty].idJuego=auxIdJuego;
                strcpy(listJuegos[indexJuegosIsEmpty].descripcion, descripcion);
                listJuegos[indexJuegosIsEmpty].importe=importe;
                listJuegos[indexJuegosIsEmpty].isEmpty=TAKEN;
                retorno=0;
            }
        }
    }
    return retorno;
}

int findJuegoById(eJuego* listJuegos, int len, int idJuego)
{
    int retorno=-1;
    int i;

    if(listJuegos!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if (listJuegos[i].idJuego == idJuego && listJuegos[i].isEmpty==TAKEN)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


int removeJuego(eJuego* listJuegos, int len, int idJuego)
{
    int retorno=-1;
    int i;

    printJuegos(listJuegos, len);
    printf ("\n Ingrese el ID del juego que desea dar de baja: ");
    scanf("%d", &idJuego);

    int indexJuegosPosition=findJuegoById(listJuegos, len, idJuego);

    for (i=0; i<len; i++)
    {
        if (indexJuegosPosition>=0)
        {
            printf ("\n El juego fue dado de baja.\n");
            listJuegos[indexJuegosPosition].isEmpty = FREE;
            system ("pause");
            break;
        }
        else
        {
            printf ("\n El ID no existe en el indice.\n");
            system ("pause");
            break;
        }
    }
    return retorno;
}

int modifyJuegos(eJuego* listJuegos, int len, int idJuego)
{
    int retorno=-1;
    int modifyOptions;
    int indexJuegos;
    char auxNewDescripcion[31];
    float auxNewImporte;
    char proceed='n';
    char opcion;

    printJuegos(listJuegos, len);
    printf("Ingrese el ID que desea modificar:\n");
    scanf("%d", &idJuego);
    indexJuegos=findJuegoById(listJuegos, len, idJuego);
    if(listJuegos!=NULL)
    {
        if(indexJuegos >= 0)
        {
            do
            {
                printf("\n%5s %20s %20s\n","ID","Descripcion","Importe");
                printJuego(listJuegos, indexJuegos);
                printf("\n\n Seleccione el campo que desea modificar:");
                printf("\n 1. Descripcion\n");
                printf(" 2. Importe\n");
                scanf("%d", &modifyOptions);
                switch(modifyOptions)
                {
                case 1:
                    getString(" Ingrese descripcion: ", auxNewDescripcion);
                    printf("Confirma la modificacion? S/N\n");
                    opcion=getChar("");
                    switch(opcion)
                    {
                    case 's':
                        strcpy(listJuegos[indexJuegos].descripcion, auxNewDescripcion);
                        printf("Modificacion realizada con exito.\n");
                        system("pause");
                        system("cls");
                        break;
                    case 'n':
                        printf("Se cancelo la modificacion.\n");
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf("Ingrese una opcion valida.\n");
                        break;
                    }
                    break;
                case 2:
                    auxNewImporte=getValidFloat(" Ingrese importe:\n"," Error, ingrese importe nuevamente (mayor a 0):\n", 1, 1000000);
                    printf("Confirma la modificacion? S/N\n");
                    opcion=getChar("");
                    switch(opcion)
                    {
                    case 's':
                        listJuegos[indexJuegos].importe=auxNewImporte;
                        printf("Modificacion realizada con exito.\n");
                        system("pause");
                        system("cls");
                        break;
                    case 'n':
                        printf("Se cancelo la modificacion.\n");
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf("Ingrese una opcion valida.\n");
                        break;
                    }
                    break;
                default :
                    printf(" Opcion incorrecta, ingrese 1 o 2.");
                }
                printf(" ¿Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&proceed);
                system("pause");
                system("cls");
            }
            while(proceed=='s' || proceed=='S');
        }
        else if(indexJuegos<0)
        {
            printf(" No existe ese ID. \n");
        }
        retorno=0;
    }
    return retorno;
}

int printJuego(eJuego* listJuegos, int indexJuegos)
{
    int retorno=-1;
    if (listJuegos!=NULL)
    {
        if(listJuegos[indexJuegos].isEmpty==TAKEN)
        {
            printf ("%5d %20s %20.2f\n", listJuegos[indexJuegos].idJuego, listJuegos[indexJuegos].descripcion, listJuegos[indexJuegos].importe);
            retorno=0;
        }
    }
    return retorno;
}

int printJuegos(eJuego* listJuegos, int len)
{
    int retorno=-1;
    int i;
    if (listJuegos!=NULL)
    {
        printf("\n%5s %20s %20s\n", "ID","Descripcion", "Importe");
        for (i=0; i<len; i++)
        {
            if(listJuegos[i].isEmpty == 0)
            {
                printJuego(listJuegos, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

