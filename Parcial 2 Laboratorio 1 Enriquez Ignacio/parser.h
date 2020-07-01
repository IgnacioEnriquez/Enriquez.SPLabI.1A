#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Obtiene todos los paises de un linkedlist
 *
 * \param pFile = Nombre del archivo
 * \param pArrayListPaises = Array de Paises
 * \return -1 si hubo un error u 0 si esta todo ok
 *
 */
int parser_PaisesFromText(FILE* pFile, LinkedList* pArrayListBicicletas);


#endif // PARSER_H_INCLUDED
