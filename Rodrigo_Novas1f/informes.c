#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "informes.h"
#include "utn.h"

int informes(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos, eCliente* listClientes,int lenClientes)
{
    char continuar= 's';
    char option;
    int myReturn=-1;
    if(listAlquileres!=NULL && listJuegos!=NULL && listClientes!=NULL)
    {
        do
        {
            printf(" ****************INFORMES****************\n\n");
            printf(" a) Promedio y total de los Importes de los juegos alquilados.\n");
            printf(" b) La cantidad de juegos cuyo Importe no superan el promedio anterior.\n");
            printf(" c) Listar todos los clientes que alquilaron un juego determinado.\n");
            printf(" d) Listar todos los juegos que fueron alquilados por un cliente determinado.\n");
            printf(" e) Listar el/los juego/s menos alquilado/s.\n");
            printf(" f) Listar el/los clientes que realizo mas alquileres.\n");
            printf(" g) Listar todos los juegos alquilados en una fecha determinada.\n");
            printf(" h) Listar todos los clientes que realizaron al menos un alquiler en una fecha determinada.\n");
            printf(" i) Listar todos los juegos ordenados por Importe (descendente), utilizando el metodo de burbujeo.\n");
            printf(" j) Listar todos los clientes ordenados por Apellido (ascendente), utilizando el metodo de insercion.\n");
            printf(" k) Salir");
            printf("\n\n Ingrese una opcion: ");
            fflush(stdin);
            scanf("%c",&option);

            switch(option)
            {
            case 'a':
                promedioTotalImporteJuegos(listAlquileres,MAXALQUILERES,listJuegos,MAXJUEGO);
                system("pause");
                system("cls");
                break;
            case 'b':
                juegosNoSuperanPromedioAnterior(listAlquileres, MAXALQUILERES,listJuegos,MAXJUEGO);
                system("pause");
                system("cls");
                break;
            case 'c':
                clientesQueAlquilaronJuegoDeterminado(listAlquileres,MAXALQUILERES,listJuegos,MAXJUEGO,listClientes,MAXCLIENTE);
                system("pause");
                system("cls");
                break;
            case 'd':
                juegosAlquiladosPorClienteDeterminado(listAlquileres,MAXALQUILERES,listJuegos,MAXJUEGO,listClientes,MAXCLIENTE);
                system("pause");
                system("cls");
                break;
            case 'e':
                juegosMenosAlquilados(listAlquileres,MAXALQUILERES,listJuegos,MAXJUEGO);
                system("pause");
                system("cls");
                break;
            case 'f':
                clienteMasAlquileres(listAlquileres,MAXALQUILERES,listClientes,MAXCLIENTE);
                system("pause");
                system("cls");
                break;
            case 'g':
                juegoAlquiladosFechaDeterminada(listAlquileres,MAXALQUILERES,listJuegos,MAXJUEGO,listClientes,MAXCLIENTE);
                system("pause");
                system("cls");
                break;
            case 'h':
                ///
                system("pause");
                system("cls");
                break;
            case 'i':
                ordenarJuegosBubbleSort(listJuegos, MAXJUEGO);
                system("pause");
                system("cls");
                break;
            case 'j':
                ordenarClientesInsertionSort(listClientes, MAXCLIENTE);
                system("pause");
                system("cls");
                break;
            case 'k':
                system("cls");
                continuar='n';
                break;
            default:
                printf(" Ingrese una opcion de la 'a' a la 'k'");
                break;
            }
        }
        while(continuar == 's' || continuar == 'S');
        myReturn=0;
    }
    return myReturn;
}
/// Opcion  A - Funciona
int promedioTotalImporteJuegos(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos)
{
    float suma=0;
    float promedio;
    int i;
    int j;
    int myReturn=-1;
    int contadorAlquileres=0;

    if(listAlquileres!=NULL &&listJuegos!=NULL)
    {
        for( i=0 ; i<lenAlquileres ; i++)
        {
            for(j=0; j<lenJuegos ; j++)
            {
                if(listAlquileres[i].idJuego == listJuegos[j].idJuego && listAlquileres[i].isEmpty == 0 && listJuegos[j].isEmpty == 0)
                {
                    suma = suma + listJuegos[j].importe;
                    contadorAlquileres ++;
                    promedio = suma / contadorAlquileres;
                }
            }

        }
        printf(" La suma de todos los juegos alquilados es %.2f y el promedio es %.2f \n", suma, promedio);
        myReturn=0;
    }

    return myReturn;
}
/// Opcion B - Funciona
int juegosNoSuperanPromedioAnterior(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos)
{
    float suma=0;
    float promedio;
    int i;
    int j;
    int myReturn=-1;
    int contadorAlquileres=0;
    int contadorMenorQuePromedio=0;

    if(listAlquileres!=NULL &&listJuegos!=NULL)
    {
        for( i=0 ; i<lenAlquileres ; i++)
        {
            for(j=0; j<lenJuegos ; j++)
            {
                if(listAlquileres[i].idJuego == listJuegos[j].idJuego && listAlquileres[i].isEmpty == 0 && listJuegos[j].isEmpty == 0)
                {
                    suma = suma + listJuegos[j].importe;
                    contadorAlquileres ++;
                    promedio = suma / contadorAlquileres;
                }
            }
        }
        for (j=0 ; j<lenJuegos ; j++)
        {
            if(listJuegos[j].isEmpty == 0)
            {
                if (listJuegos[j].importe < promedio)
                {
                    contadorMenorQuePromedio++;///una vez que el promedio se saca arriba, y compara el precio del juego en determinada posicion con el promedio, si el precio del juego es menor al promedio le suma +1 a este contador
                }
            }
        }
        printf (" %d juegos no superan el promedio anterior. \n", contadorMenorQuePromedio);
        myReturn=0;
    }
    return myReturn;
}

///Opcion C - NO BUSCA EL ID DE JUEGO Y CIERRA EL PROGRAMA, REVISAR
int clientesQueAlquilaronJuegoDeterminado(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos, eCliente* listClientes,int lenClientes)
{
    int myReturn=-1;
    int i;
    int j;
    int idJuego;
    int indexJuego;

    if(listAlquileres!=NULL && listClientes!=NULL && listJuegos!=NULL)
    {
        printJuegos(listJuegos, lenJuegos);
        printf("\n Ingrese el ID de juego: ");
        fflush(stdin);
        scanf("%d",&idJuego);

        indexJuego = findJuegoById(listJuegos, lenJuegos, idJuego);

        if (indexJuego != -1)
        {
            for (i=0; i<lenAlquileres; i++)
            {
                if (listAlquileres[i].isEmpty == 0)
                {
                    if (idJuego == listAlquileres[i].idJuego)
                    {
                        for (j=0; j<lenClientes; j++)
                        {
                            if (listAlquileres[i].id == listClientes[j].id)
                            {
                                printCliente(listClientes, listClientes[j].id);
                                myReturn=0;
                            }

                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("\n No existe el ID de juego.\n\n");
    }
    return myReturn;
}

///Opcion D - Revisar
int juegosAlquiladosPorClienteDeterminado(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos,eCliente* listClientes,int lenClientes)
{
    int myReturn=-1;
    int i;
    int j;
    int id;
    int indexCliente;
    if(listAlquileres!=NULL && listClientes!=NULL && listJuegos!=NULL)
    {
        printClientes(listClientes, lenClientes);
        printf("\n Ingrese el ID de cliente: ");
        scanf("%d",&id);
        indexCliente = findClienteById(listClientes, lenClientes, id);

        if (indexCliente !=-1)
        {
            for (i=0; i<lenAlquileres; i++)
            {
                if (listAlquileres[i].isEmpty == 0)
                {
                    if (id == listAlquileres[i].id)
                    {
                        for (j=0; j<lenJuegos; j++)
                        {
                            if (listAlquileres[i].idJuego == listJuegos[j].idJuego)
                            {
                                printJuegos(listJuegos, listJuegos[j-1].idJuego);
                                myReturn=0;
                            }

                        }
                    }
                }
            }
        }
        else
        {
            printf("\n No existe el ID de cliente. \n\n");
        }
    }

    return myReturn;
}

///Opcion E - Funciona
int juegosMenosAlquilados(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos)
{
    int myReturn=-1;
    int i;
    int j;
    int flagPrimerMinimo = 1;
    int juegosMinimo;
    int acumuladorCliente;
    if(listAlquileres!=NULL && listJuegos!=NULL)
    {
        for(i=0; i<lenJuegos; i++)
        {
            acumuladorCliente=0;
            for(j=0; j<lenAlquileres; j++)
            {
                if(listJuegos[i].idJuego == listAlquileres[j].idJuego && listAlquileres[j].isEmpty==0 && listJuegos[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            if(flagPrimerMinimo || (acumuladorCliente < juegosMinimo && acumuladorCliente > 0 ))
            {
                flagPrimerMinimo = 0;
                juegosMinimo = acumuladorCliente;
            }
        }
        for(i=0; i<lenJuegos; i++)
        {
            acumuladorCliente=0;
            for(j=0; j<lenAlquileres; j++)
            {
                if(listJuegos[i].idJuego == listAlquileres[j].idJuego && listAlquileres[j].isEmpty==0 && listJuegos[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            if(acumuladorCliente == juegosMinimo)
            {
                printJuego(listJuegos, i);
            }

        }
        myReturn=0;
    }
    return myReturn;
}

///Opcion F - Revisar
int clienteMasAlquileres(eAlquiler* listAlquileres, int lenAlquileres, eCliente* listClientes,int lenClientes)
{
    int myReturn=-1;
    int i;
    int j;
    int clientesMaximo=0;
    int acumuladorCliente;
    if(listAlquileres!=NULL && listClientes!=NULL)
    {
        for(i=0; i<lenClientes; i++)
        {
            acumuladorCliente=0;
            for(j=0; j<lenAlquileres; j++)
            {
                if(listClientes[i].id == listAlquileres[j].id && listAlquileres[j].isEmpty==0 && listClientes[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            if(acumuladorCliente>clientesMaximo)
            {
                clientesMaximo=acumuladorCliente;
            }
        }
        for(i=0; i<lenClientes; i++)
        {
            acumuladorCliente=0;
            for(j=0; j<lenAlquileres; j++)
            {
                if(listClientes[i].id == listAlquileres[j].id && listAlquileres[j].isEmpty==0 && listClientes[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            if(acumuladorCliente == clientesMaximo)
            {
                printCliente(listClientes, i);
            }
        }
        myReturn=0;
    }
    return myReturn;
}

///Opcion G - Funciona
int juegoAlquiladosFechaDeterminada(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos,eCliente* listClientes,int lenCliente )
{
    int myReturn=-1;
    int dia;
    int mes;
    int anio

    ;
    int i;
    int j;

    if(listAlquileres!=NULL  && listClientes!=NULL &&  listJuegos!=NULL)
    {
        printf(" Ingrese el dia en el que fue alquilado el juego: ");
        scanf("%d",&dia);
        printf(" Ingrese mes: ");
        scanf("%d",&mes);
        printf(" Ingrese anio: ");
        scanf("%d",&anio);

        for(i=0; i<lenAlquileres ; i++)
        {
            if(listAlquileres[i].fechaIngreso.dia == dia && listAlquileres[i].fechaIngreso.mes == mes && listAlquileres[i].fechaIngreso.anio == anio && listAlquileres[i].isEmpty == 0)
            {
                for(j=0; j<lenJuegos; j++)
                {
                    if(listJuegos[j].idJuego == listAlquileres[i].idJuego && listJuegos[j].isEmpty == 0)
                    {
                        printJuego(listJuegos, listJuegos[j-1].idJuego);
                        myReturn=0;
                    }
                }

            }
        }

    }
    return myReturn;
}

///Opcion H

///Opcion I - Funciona
int ordenarJuegosBubbleSort(eJuego *listJuegos, int lenJuegos)
{
    eJuego auxJuegos;
    int i;
    int j;
    int myReturn=-1;
    if(listJuegos!=NULL )
    {
        for (i=0; i<lenJuegos; i++)
        {
            for (j=i+1; j<lenJuegos; j++)
            {
                if (listJuegos[j].importe > listJuegos[i].importe)
                {
                    auxJuegos = listJuegos[i];
                    listJuegos[i] = listJuegos[j];
                    listJuegos[j] = auxJuegos;
                }
            }
        }
        printJuegos(listJuegos, lenJuegos);
        myReturn=0;
    }
    return myReturn;
}

///Opcion J - Funciona
int ordenarClientesInsertionSort(eCliente *listClientes, int lenClientes)
{
    eCliente myAux;
    int myReturn=-1;
    int i;
    int j;
    if(listClientes!=NULL)
    {
        for (i=1; i < lenClientes; i++)
        {
            myAux = listClientes[i];
            j = i-1;
            while (strcmp(listClientes[j].apellido, myAux.apellido) > 0 && j>=0)
            {
                listClientes[j+1] = listClientes[j];
                j--;
            }
            listClientes[j+1] = myAux;
        }
        printClientes(listClientes, lenClientes);
        myReturn=0;
    }
    return myReturn;
}

