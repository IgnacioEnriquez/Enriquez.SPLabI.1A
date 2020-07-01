#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[50];
    int recuperados;
    int infectados;
    int muertos;

} ePais;

/** brief Guarda un nuevo pais en la memoria dinamica con espacios vacios
 *
 *
 *
 * return pais guardado en memoria dinamica
 */
ePais* paises_new();

/** brief Se le asignan los parametros tipo string
 *
 *	param id tipo string
 *	param nombre
 *	param infectados tipo string
 *	param recuperados tipo string
 *	param muertos tipo string
 *  return
 */
ePais* pais_newParametros(char* idStr,char* nombreStr,char* infectadosStr,char* recuperadosStr,char* muertosStr);

/** brief setea el id a un pais
 *
 * param pais
 * param id a setear
 *
 * return si todo esta ok 0, si no -1
 *
 */
int pais_setId(ePais* pais,int id);

/** brief setea el numero de recuperados a un pais
 *
 * param pais
 * param recuperados a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_setRecuperados(ePais* pais,int recuperados);

/** brief setea el numero de infectados a un pais
 *
 * param pais
 * param infectados a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_setInfectados(ePais* pais,int infectados);

/** brief setea el numero de muertos a un pais
 *
 * param pais
 * param muertos a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_setMuertos(ePais* pais,int muertos);

/** brief setea el nombre a un pais

 *
 * param pais
 * param nombre a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_setNombre(ePais* pais,char* nombre);

/** brief obtener el id de un pais
 *
 * param pais
 * param id en el que se va a guardar el id obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_getId(ePais* pais,int* id);

/** brief obtener el numero de recuperados de un pais
 *
 * param pais
 * param int en el que se va a guardar el numero de recuperados obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_getRecuperados(ePais* pais,int* recuperados);

/** brief obtener el nombre de un pais
 *
 * param pais
 * param char en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_getNombre(ePais* pais,char* nombre);

/** brief obtener el numero de infectados de un pais
 *
 * param pais
 * param int en el que se va a guardar el numero de infectados obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_getInfectados(ePais* pais,int* infectados);

/** brief obtener el numero de muertos de un pais
 *
 * param pais
 * param int en el que se va a guardar el numero de muertos obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int pais_getMuertos(ePais* pais,int* muertos);

/** \brief Muestra un solo pais
 *
 * \param  ePais* puntero al pais
 * \return int
 *
 */
int mostrarPais( ePais* pais);

/** \brief Muestra Todos los paises de un array
 *
 * \param  LinkedList* pArrayListPaises
 * \return int
 *
 */
int mostrarPaises(LinkedList* pArrayListPaises);

/** \brief Asigna un numero aleatorio de recuperados,infectados y muertos
 *
 * \param  void* x
 * \return 1 si debe modificarse,0 si no
 *
 */
void* assignEstadisticas(void* x);

/** \brief Filtra los paises con menos de 5000 muertes
 *
 * \param  void* x
 * \return 1 si debe modificarse,0 si no
 *
 */
int filtroPaisesExitosos(void* x);

/** \brief Filtra los paises con una cantidad de infectados mayor al triple de recuperados
 *
 * \param  void* x
 * \return 1 si debe modificarse,0 si no
 *
 */
int filtroPaisesAlHorno(void* x);

/** \brief Ordena los infectados pasando el valor 0 u 1
 *
 * \param  void* x,void* y
 * \return 1 si debe modificarse,0 si no
 *
 */
int OrdenarPaisByInf(void* x, void* y);


#endif // BICICLETAS_H_INCLUDED
