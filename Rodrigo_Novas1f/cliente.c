#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "utn.h"

/** \brief Generates an unique ID for each employee
 *
 * \return unique ID
 *
 */
static int generateNextId ()
{
    static int id=0;

    id ++;

    return id;
}

int initCliente (eCliente* listClientes, int len)
{
    int retorno=-1;
    int i;
    if(listClientes !=NULL)// && len>0)
    {
        for(i=0; i<len; i++)
        {
            listClientes[i].isEmpty=1;//FREE;
        }
        retorno=0;
    }
    return retorno;
}

int obtainFreeSlot (eCliente* listClientes, int len)
{
    int retorno=-1;
    int i;
    if(listClientes != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(listClientes[i].isEmpty == 1)//FREE)
            {
                retorno = i;
                break;
            }
        }

    }

    return retorno;
}

int findClienteById(eCliente* listClientes, int len, int id)
{
    int retorno=-1;
    int i;

    if(listClientes!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if (listClientes[i].id == id && listClientes[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


int printCliente(eCliente* listClientes, int index)
{
    int retorno=-1;
    if (listClientes!=NULL)
    {
        if(listClientes[index].isEmpty==0)
        {
            printf ("%5d %20s %20s %5c %20s\n", listClientes[index].id, listClientes[index].apellido, listClientes[index].nombre, listClientes[index].sexo, listClientes[index].domicilio);
            retorno=0;
        }
    }
    return retorno;
}

int printClientes(eCliente* listClientes, int len)
{
    int retorno=-1;
    int i;
    if (listClientes!=NULL)
    {
        printf("\n%5s %20s %20s %5s %20s \n", "ID","Apellido","Nombre","Sexo","Domicilio");
        for (i=0; i<len; i++)
        {
            if(listClientes[i].isEmpty == 0)
            {
                printCliente(listClientes, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

int addCliente(eCliente* listClientes, int len)
{
    int retorno=-1;
    eCliente auxCliente;
    int freeSlot = obtainFreeSlot(listClientes, len);

    if(listClientes != NULL)
    {
        if(freeSlot != -1)
        {
            getValidString(" Ingrese apellido del cliente: ", "Error, ingrese nuevamente.", auxCliente.apellido);
            getValidString(" Ingrese nombre del cliente: ", "Error, ingrese nuevamente.", auxCliente.nombre);
            getValidSexo(" Ingrese sexo, f o m: ", &auxCliente.sexo);
            getString(" Ingrese el domicilio del cliente: ",auxCliente.domicilio );
            auxCliente.id = generateNextId();
            auxCliente.isEmpty = 0;
            listClientes[freeSlot] = auxCliente;
            retorno = 0;
        }
    }

    return retorno;
}

int removeCliente(eCliente* listClientes, int len, int id)
{
    int retorno=-1;
    int i;
    printClientes(listClientes, MAXCLIENTE);
    printf ("\n Ingrese el ID del cliente que desea dar de baja: ");
    scanf("%d", &id);

    int clienteIndexPosition=findClienteById(listClientes, len, id);

    for (i=0; i<len; i++)
    {
        if (clienteIndexPosition>=0)
        {
            printf ("\n El cliente fue dado de baja.\n");
            listClientes[clienteIndexPosition].isEmpty = FREE;
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

int modifyCliente(eCliente* listClientes, int len, int id)
{
    int retorno=-1;
    int modifyOptions;
    int index;
    char auxNewNombre[31];
    char auxNewApellido[31];
    char auxNewSexo;
    char auxNewDomicilio[31];
    char proceed='n';
    char opcion;

    printClientes(listClientes, MAXCLIENTE);
    printf(" Ingrese el ID que desea modificar:\n");
    scanf("%d", &id);
    index=findClienteById(listClientes, len, id);
    if(listClientes!=NULL)
    {
        if(index >= 0)
        {
            do
            {
                printf("\n%5s %20s %20s %10s %3s \n", "ID","Apellido","Nombre","Sexo","Domicilio");
                printCliente(listClientes, index);
                printf("\n\n Seleccione el campo que desea modificar:");
                printf("\n 1. Apellido\n");
                printf(" 2. Nombre\n");
                printf(" 3. Sexo\n");
                printf(" 4. Domicilio\n");
                scanf("%d", &modifyOptions);
                switch(modifyOptions)
                {
                case 1:
                    getValidString(" Ingrese apellido:\n", " Error, ingrese apellido nuevamente (solo letras):", auxNewApellido);
                    printf(" Confirma la modificacion? s/n\n");
                    opcion=getChar("");
                    switch(opcion)
                    {
                    case 's':
                        strcpy(listClientes[index].apellido, auxNewApellido);
                        printf(" Modificacion realizada con exito.\n");
                        system("pause");
                        system("cls");
                        break;
                    case 'n':
                        printf(" Se cancelo la modificacion.\n");
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf(" Ingrese una opcion valida.\n");
                        break;
                    }
                    break;
                case 2:
                    getValidString(" Ingrese nombre:\n"," Error, ingrese los datos nuevamente", auxNewNombre);
                    printf(" Confirma la modificacion? s/n\n");
                    opcion=getChar("");
                    switch(opcion)
                    {
                    case 's':
                        strcpy(listClientes[index].nombre, auxNewNombre);
                        printf(" Modificacion realizada con exito.\n");
                        system("pause");
                        system("cls");
                        break;
                    case 'n':
                        printf(" Se cancelo la modificacion.\n");
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf(" Ingrese una opcion valida.\n");
                        break;
                    }
                    break;
                case 3:
                    getValidSexo(" Ingrese sexo:\n", &auxNewSexo);
                    printf(" Confirma la modificacion? s/n\n");
                    opcion=getChar("");
                    switch(opcion)
                    {
                    case 's':
                        listClientes[index].sexo = auxNewSexo;
                        printf(" Modificacion realizada con exito.\n");
                        system("pause");
                        system("cls");
                        break;
                    case 'n':
                        printf(" Se cancelo la modificacion.\n");
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf(" Ingrese una opcion valida.\n");
                        break;
                    }
                    break;
                case 4:
                    getString(" Ingrese domicilio:\n", auxNewDomicilio);
                    printf(" Confirma la modificacion? S/N\n");
                    opcion=getChar("");
                    switch(opcion)
                    {
                    case 's':
                        strcpy(listClientes[index].domicilio, auxNewDomicilio);
                        printf(" Modificacion realizada con exito.\n");
                        system("pause");
                        system("cls");
                        break;
                    case 'n':
                        printf(" Se cancelo la modificacion.\n");
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf(" Ingrese una opcion valida.\n");
                        break;
                    }
                    break;
                default:
                    printf(" Opcion incorrecta, ingrese un numero del 1 al 4.");
                }
                printf(" ¿Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&proceed);
                system("pause");
                system("cls");
            }
            while(proceed=='s' || proceed=='S');
        }
        else if(index<0)
        {
            printf(" No existe ese ID. \n");
        }
        retorno=0;
    }
    return retorno;
}




