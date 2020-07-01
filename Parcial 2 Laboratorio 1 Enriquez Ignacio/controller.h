#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



/** \brief Pide un nombre a un archivo y obtiene todos los paises de un linkedlist
 *
 * \param pArrayListPaises = Array de Paises
 * \return -1 si hubo un error u 0 si esta todo ok
 *
 */
int controller_loadFromText(LinkedList* pArrayListBicicletas);
/** \brief Muestra todos los paises de un LinkedList
 *
 * \param pArrayListPaises = Array de Paises
 * \return 0 si esta todo ok
 *
 */
int controller_ListPaises(LinkedList* pArrayListPaises);
/** \brief Guarda los datos de un pais en el archivo data.csv (modo texto).
 *
 * \param file char*
 * \param pArrayListPaises LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* file, LinkedList* pArrayListPaises);
/** \brief Asigna un numero aleatorio de recuperados,infectados y muertos
 *
 * \param  void* x
 * \return 1 si debe modificarse,0 si no
 *
 */
int controller_asignarEstadisticas(LinkedList* pArrayListPaises);
/** \brief Genera un archivo en donde se encuentran los  paises con menos de 5000 muertos
 *
 * \param pArrayListPaises = Array de Paises
 * \return 1 si hubo un error u 0 si esta todo ok
 *
 */
int controller_listPaisesExitosos(LinkedList* pArrayListPaises);
/** \brief Genera un archivo en donde se encuentran los  paises con menos de 5000 muertos
 *
 * \param pArrayListPaises = Array de Paises
 * \return 1 si hubo un error u 0 si esta todo ok
 *
 */
int controller_listPaisesAlHorno(LinkedList* pArrayListPaises);
/** \brief Ordenar los paises por nivel de infeccion
 *
 * \param pArrayListPaises LinkedList*
 * \return int
 *
 */
int controller_sortNivelInfeccion(LinkedList* pArrayListPaises);
/** \brief Informa el pais con mayor numero de muertes
 *
 * \param  void* x
 * \return 1 si debe modificarse,0 si no
 *
 */
int controller_informarMasCastigado(LinkedList* pArrayListPaises);
#endif // CONTROLLER_H_INCLUDED
