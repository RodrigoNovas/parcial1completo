#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#define FREE 1
#define TAKEN 0
#define MAXCLIENTE 10
#define MAXJUEGO 10
#define MAXALQUILERES 10
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "utn.h"


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idAlquiler;
    int idJuego;
    int id;
    eFecha fechaIngreso;
    int isEmpty;
} eAlquiler;

/** \brief Obtiene el primer espacio libre para cargar un alquiler
 *
 * \param eAlquiler* listAlquileres
 * \param int len
 * \return Retorna (0) en caso de encontrar espacio o (-1) en caso de error
 *
 */
int obtainFreeSlotAlquiler(eAlquiler* listAlquileres, int len);

/** \brief Inicializa el array de alquileres en 0
 *
 * \param eAlquiler* listAlquileres
 * \param int len
 * \return Retorna (0) en caso de inicializar correctamente o (-1) en caso de error
 *
 */
int initAlquiler(eAlquiler* listAlquileres, int len);

/** \brief Toma los el ID de un juego y el ID de un cliente para dar de alta un alquiler y listarlo en la lista de alquileres
 *
 * \param eAlquiler* listAlquileres
 * \param int lenAlquileres
 * \param eJuego* listJuegos
 * \param int lenJuegos
 * \param eCliente* listClientes
 * \param int lenClientes
 * \return int Retorna (0) en caso de cargarse con exito o (-1) en caso de error
 *
 */
int addAlquiler(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos, int lenJuegos, eCliente* listClientes, int lenClientes);

/** \brief Busca un alquiler por su numero de ID
 *
 * \param eAlquiler* listAlquileres
 * \param int len
 * \param int idAlquiler
 * \return int Retorna el número de la posición correspondiente al ID de alquiler buscado o (-1) en caso de error
 *
 */
int findAlquilerById(eAlquiler* listAlquileres, int len, int idAlquiler);

/** \brief Ingresa un ID de un juego a ser alquilado
 *
 * \param listJuegos
 * \param int len
 * \return idJuego
 *
 */
int addJuegoById(eJuego* listJuegos, int len);

/** \brief Ingresa un ID de un cliente que hara un alquiler
 *
 * \param listClientes
 * \param int len
 * \return id
 *
 */
int addClienteById(eCliente* listCliente, int len);

#endif // ALQUILERES_H_INCLUDED

