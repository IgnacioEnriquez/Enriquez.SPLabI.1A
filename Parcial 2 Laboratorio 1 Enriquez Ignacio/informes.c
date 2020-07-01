#include <stdio.h>
#include <stdlib.h>
#include "paises.h"
#include "string.h"
#include "LinkedList.h"
#include "funcionesUTN.h"
#include "parser.h"
#include "informes.h"
#include "controller.h"


int menu()
{
    int retorno;

    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar Estadisticas\n");
    printf("4. Filtrar por paises exitosos\n");
    printf("5. Mostrar por paises en el horno\n");
    printf("6. Ordenar por nivel de infeccion\n");
    printf("7. Mostrar Mas Castigado\n");
    printf("8. Salir\n\n");
    printf("Ingrese una opcion : ");
    fflush(stdin);
    scanf("%d",&retorno);


    return retorno;
}
