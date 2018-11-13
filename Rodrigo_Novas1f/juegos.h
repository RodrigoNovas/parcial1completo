#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED
#define FREE 1
#define TAKEN 0
#define ASCENDENTE 1
#define DESCENDENTE 0
#define MAXCLIENTE 10
#define MAXJUEGO 10
#define MAXALQUILERES 10

typedef struct
{
    int idJuego;///codigo de juego
    char descripcion[51];
    float importe;
    int isEmpty;
}eJuego;

/** \brief Obtiene un espacio libre en el array para cargar un juego
 *
 * \param eJuego* listJuegos
 * \param int len
 * \return
 *
 */
int obtainFreeSlotJuego (eJuego* listJuegos, int len);

/** \brief Inicializa la el array de juegos en (0)
 *
 * \param eJuego* listJuegos
 * \param int len
 * \return Retorna (0) en caso de inicializar correctamente o (-1) en caso de error
 *
 */
int initJuego(eJuego* listJuegos, int len);

/** \brief Agrega un juego
 *
 * \param eJuego* listJuegos
 * \param int len
 * \param int idJuego
 * \param char descripcion []
 * \param float importe
 * \return int Retorna (0) en caso de cargarse con exito o (-1) en caso de error
 *
 */
int addJuego(eJuego* listJuegos, int len, int idJuego, char descripcion [], float importe);

/** \brief Busca el juego por número de ID
 *
 * \param eJuego* listJuegos
 * \param int len
 * \param int idJuego
 * \return int Retorna el número de la posición correspondiente al ID buscado o (-1) en caso de error
 *
 */
int findJuegoById(eJuego* listJuegos, int len, int idJuego);

/** \brief Borra un juego por ID
 *
 * \param eJuego* listJuegos
 * \param int len
 * \param int idJuego
 * \return retorna (0) en caso de que se haya borrado el juego o (-1) en caso de que no haya juegos cargados
 *
 */
int removeJuego(eJuego* listJuegos, int len, int idJuego);

/** \brief Modifica los datos de un juego cargado por ID
 *
 * \param eJuego* listJuegos
 * \param int len
 * \param int idJuego
 * \return retorna (0) en caso de que se haya modificado el juego o (-1) en caso de que no haya juegos cargados
 *
 */
int modifyJuegos(eJuego* listJuegos, int len, int idJuego);

/** \brief Imprime los datos del juego, ID, descripcion e importe
 *
 * \param eJuego* listJuegos
 * \param int len
 * \return retorna (0) en caso de que haya un juego cargado o (-1) en caso de error
 *
 */
int printJuego(eJuego* listJuegos, int len);

/** \brief Imprime los datos de todos los juegos cargados
 *
 * \param eJuego* listJuegos
 * \param int idJuego
 * \return retorna (0) en caso de que haya juegos cargados o (-1) en caso de error
 *
 */
int printJuegos(eJuego* listJuegos, int len);

/** \brief Generates an unique ID for each employee
 *
 * \return unique ID
 *
 */

#endif

