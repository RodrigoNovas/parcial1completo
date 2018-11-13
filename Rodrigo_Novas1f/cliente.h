#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#define FREE 1
#define TAKEN 0
#define MAXCLIENTE 10
#define MAXJUEGO 10
#define MAXALQUILERES 10

typedef struct
{
    int id;///codigo cliente
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int isEmpty;
}eCliente;

/** \brief Busca el primer espacio disponible para un cliente
 *
 * \param eCliente* listClientes
 * \param int len
 * \return Retorna (0) en caso de encontrar espacio o (-1) en caso de error
 *
 */
int obtainFreeSlot(eCliente* listClientes, int len);

/** \brief Inicializa el array de clientes en 0
 *
 * \param eCliente* listClientes
 * \param int len
 * \return Retorna (0) en caso de inicializar correctamente o (-1) en caso de error
 *
 */
int initCliente(eCliente* listClientes, int len);


/** \brief Agrega un cliente
 *
 * \param eCliente* listClientes
 * \param int len
 * \return int Retorna (0) en caso de cargarse con exito o (-1) en caso de error
 *
 */
int addCliente(eCliente* listClientes, int len);


/** \brief Busca un cliente por su numero de ID
 *
 * \param eCliente* listClientes
 * \param int len
 * \param int id
 * \return int Retorna el número de la posición correspondiente al ID buscado o (-1) en caso de error
 *
 */
int findClienteById(eCliente* listClientes, int len, int id);


/** \brief Borra un cliente
 *
 * \param eCliente* listClientes
 * \param int len
 * \param int id
 * \return int Retorna (0) en caso de haberse borrado con éxito o (-1) en caso de error
 *
 */
int removeCliente(eCliente* listClientes, int len, int id);


/** \brief Modifica un cliente
 *
 * \param eCliente* listClientes
 * \param int len
 * \param int id
 * \return int Retorna (0) en caso de modificarse con éxito o (-1) en caso de error
 *
 */
int modifyCliente(eCliente* listClientes, int len, int id);

/** \brief Imprime un cliente
 *
 * \param eCliente* listClientes
 * \param int len
 * \return retorna un cliente (0) en caso de que haya un cargado o (-1) en caso de que no haya un cliente cargado
 *
 */
int printCliente(eCliente* listClientes, int len);

/** \brief Imprime una lista de clientes
 *
 * \param eCliente* listClientes
 * \param int len
 * \return retorna (0) en caso de que haya clientes cargados o (-1) en caso de que no haya clientes cargados
 */
int printClientes (eCliente* listClientes, int len);

#endif

