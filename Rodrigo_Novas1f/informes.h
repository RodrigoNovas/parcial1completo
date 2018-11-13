#define FREE 1
#define TAKEN 0
#define MAXCLIENTE 10
#define MAXJUEGO 10
#define MAXALQUILERES 10
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "utn.h"


/** \brief Submenu de informes
 *
 * \param listAlquileres eAlquiler*
 * \param lenAlquileres int
 * \param listJuegos eJuego*
 * \param lenJuegos int
 * \param listaCliente eCliente*
 * \param lenCliente int
 * \return int
 *
 */
int informes(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos, eCliente* listClientes,int lenCliente);

///Opcion A
/** \brief Hace la suma y el promedio de todos los juegos alquilados
 *
 * \param listAlquileres eAlquiler*
 * \param lenAlquileres int
 * \param listJuegos eJuego*
 * \param lenJuegos int
 * \return int
 *
 */
int promedioTotalImporteJuegos(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos);

///Opcion B
/** \brief
 *
 * \param listAlquileres eAlquiler*
 * \param lenAlquileres int
 * \param listJuegos eJuego*
 * \param lenJuegos int
 * \return int
 *
 */
int juegosNoSuperanPromedioAnterior(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos);

///Opcion C REVISAR
/** \brief
 *
 * \param listAlquileres eAlquiler*
 * \param lenAlquileres int
 * \param listJuegos eJuego*
 * \param lenJuegos int
 * \param listClientes eCliente*
 * \param lenClientes int
 * \return int
 *
 */
int clientesQueAlquilaronJuegoDeterminado(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos, eCliente* listClientes,int lenClientes);

///Opcion D REVISAR
/** \brief
 *
 * \param listAlquileres eAlquiler*
 * \param lenAlquileres int
 * \param listJuegos eJuego*
 * \param lenJuegos int
 * \param listClientes eCliente*
 * \param lenClientes int
 * \return int
 *
 */
int juegosAlquiladosPorClienteDeterminado(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos,eCliente* listClientes,int lenClientes);

///Opcion E
/** \brief
 *
 * \param listAlquileres eAlquiler*
 * \param lenAlquileres int
 * \param listJuegos eJuego*
 * \param lenJuegos int
 * \return int
 *
 */
int juegosMenosAlquilados(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos);

///Opcion F REVISAR
/** \brief
 *
 * \param listAlquileres eAlquiler*
 * \param lenAlquileres int
 * \param listClientes eCliente*
 * \param lenClientes int
 * \return int
 *
 */
int clienteMasAlquileres(eAlquiler* listAlquileres, int lenAlquileres, eCliente* listClientes,int lenClientes);

///Opcion G
/** \brief
 *
 * \param listAlquileres eAlquiler*
 * \param lenAlquileres int
 * \param listJuegos eJuego*
 * \param lenJuegos int
 * \param listClientes eCliente*
 * \param lenCliente int
 * \return int
 *
 */
int juegoAlquiladosFechaDeterminada(eAlquiler* listAlquileres, int lenAlquileres, eJuego* listJuegos,int lenJuegos,eCliente* listClientes,int lenCliente);

///Opcion I
/** \brief Ordena los juegos de forma descendente (importe, mayor a menor)
 *
 * \param listJuegos eJuegos*
 * \param lenJuegos int
 * \return int retorna (0) en caso de que se haya ordernado exitosamente o (-1) en caso de error
 *
 */
int ordenarJuegosBubbleSort(eJuego *listJuegos, int lenJuegos);

///Opcion J
/** \brief Ordena los clientes de forma ascendente (apellido, menor a mayor)
 *
 * \param listClientes eCliente*
 * \param lenClientes int
 * \return int retorna (0) en caso de que se haya ordernado exitosamente o (-1) en caso de error
 *
 */
int ordenarClientesInsertionSort(eCliente *listClientes, int lenClientes);

