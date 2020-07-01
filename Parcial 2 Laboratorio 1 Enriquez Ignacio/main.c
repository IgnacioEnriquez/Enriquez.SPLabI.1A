#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "funcionesUTN.h"
#include "parser.h"
#include "informes.h"
#include "controller.h"
#include "paises.h"
#include "time.h"

/****************************************************
    Menu:
     1. Cargar archivo
     2. Imprimir lista
     3. Asignar Estadisticas
     4. Filtrar por paises exitosos
     5. Filtrar por paises en el horno
     6. Filtrar por nivel de infeccion
     7. Mostrar mas castigado
     8. Salir
*****************************************************/

int main()
{
    srand(time(NULL));
    LinkedList* listaPaises = ll_newLinkedList();

        char seguir = 'S';

        do{
               system("cls");
                switch(menu())
                {
                case 1 :
                     if(((controller_loadFromText(listaPaises))) == 0)
                {
                    system("cls");
                    printf("-------------------------------------------\n");
                    printf("Archivo cargado correctamente\n");
                    printf("-------------------------------------------\n");
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    printf("-------------------------------------------\n");
                    printf("Error al cargar el archivo");
                    printf("-------------------------------------------\n");
                    system("pause");
                    break;
                }

                case 2:
                    controller_ListPaises(listaPaises);
                    break;

                case 3:
                     if(((controller_asignarEstadisticas(listaPaises))) == 0)
                {
                    mostrarPaises(listaPaises);
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    printf("-------------------------------------------\n");
                    printf("Error,no se pudieron asignar tiempos");
                    printf("-------------------------------------------\n");
                    system("pause");
                    break;
                }

                    break;

                case 4:
                    controller_listPaisesExitosos(listaPaises);
                    break;

                case 5:
                    controller_listPaisesAlHorno(listaPaises);
                    break;

                case 6:

                    controller_sortNivelInfeccion(listaPaises);
                    break;

                case 7:
                    controller_informarMasCastigado(listaPaises);
                    break;

                case 8:
                    seguir = 'N';
                   break;



             }

        }while(seguir == 'S');



ll_deleteLinkedList(listaPaises);


    return 0;
}
