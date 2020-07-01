#include <stdio.h>
#include <stdlib.h>
#include "paises.h"
#include "string.h"
#include "LinkedList.h"
#include "funcionesUTN.h"
#include "parser.h"
#include "informes.h"
#include "controller.h"


int controller_loadFromText(LinkedList* pArrayListPaises)
{
    char nombreFile[50];
    int retorno = 1;


    if((utn_getCadena(nombreFile,50,0,"Ingrese el nombre del archivo sin las siglas .csv[Ejemplo : pandemia] : ","Error : Nombre ingresado incorrectamente,reingrese datos")) == 0);
    {
        strcat(nombreFile,".csv");

        FILE* f = fopen(nombreFile,"r");

        retorno = parser_PaisesFromText(f,pArrayListPaises);

        fclose(f);
    }


    return retorno;
}

int controller_ListPaises(LinkedList* pArrayListPaises)
{

    mostrarPaises(pArrayListPaises);
    system("pause");

    return 0;
}


int controller_listPaisesExitosos(LinkedList* pArrayListPaises)
{
    int retorno = 1;

    if(pArrayListPaises != NULL)
    {

        LinkedList* listaFiltrada = NULL;

        if(listaFiltrada == NULL)
        {
            listaFiltrada = ll_newLinkedList();

            listaFiltrada =  ll_filter(pArrayListPaises,filtroPaisesExitosos);

            retorno = 0;

            controller_saveAsText("PaisesExitosos.csv",listaFiltrada);

            ll_deleteLinkedList(listaFiltrada);

        }


    }
    return retorno;

}

int controller_listPaisesAlHorno(LinkedList* pArrayListPaises)
{
    int retorno = 1;

    if(pArrayListPaises != NULL)
    {

        LinkedList* listaFiltrada = NULL;

        if(listaFiltrada == NULL)
        {
            listaFiltrada = ll_newLinkedList();

            listaFiltrada =  ll_filter(pArrayListPaises,filtroPaisesAlHorno);

            retorno = 0;

            controller_saveAsText("PaisesAlHorno.csv",listaFiltrada);

            ll_deleteLinkedList(listaFiltrada);

        }


    }
    return retorno;

}
int controller_saveAsText(char* file, LinkedList* pArrayListPaises)
{
    int todoOk = 1;

    FILE* pf;
    char auxNombre[20];
    int auxId;
    int auxRecuperados;
    int auxInfectados;
    int auxMuertos;

    int tam = ll_len(pArrayListPaises);
    ePais* pPais;


    pf = fopen(file, "w");


    if(pf != NULL)
    {

        for(int i = 0; i < tam; i++)
        {
            pPais = ll_get(pArrayListPaises, i);

            if((pais_getId(pPais, &auxId)==0) &&
                    (pais_getNombre(pPais, auxNombre) ==0) &&
                    (pais_getRecuperados(pPais, &auxRecuperados)==0) &&
                    (pais_getInfectados(pPais,&auxInfectados)==0)&&
                    (pais_getMuertos(pPais,&auxMuertos)==0))
            {
                fprintf(pf, "%d,%s,%d,%d,%d\n", auxId, auxNombre, auxRecuperados, auxInfectados,auxMuertos);
                todoOk = 0;
            }
        }
        fclose(pf);
        printf("Archivo guardado con exito\n");
        system("pause");
    }


    return todoOk;
}

int controller_asignarEstadisticas(LinkedList* pArrayListPaises)
{
    int retorno = -1;

    if(pArrayListPaises != NULL)
    {
        pArrayListPaises = ll_map(pArrayListPaises,assignEstadisticas);

        retorno = 0;

    }

    return retorno;
}
int controller_MasCastigado(LinkedList* pArrayListPaises)
{
    int retorno = -1;
    int muertos1 = 0;
    int muertos2 = 0;
    int muertosMaximo = 0;
    void* paisMaximo;
    int flag = 0;
    void* pElement1;
    void* pElement2;


    if(pArrayListPaises != NULL)
    {
        for(int i = 0; ll_len(pArrayListPaises) -1 ; i++)
        {
            for(int j = i + 1; j < ll_len(pArrayListPaises); j++)
            {
                pElement1 = ll_get(pArrayListPaises, i);
                pElement2 = ll_get(pArrayListPaises, j);

                pais_getMuertos(pElement1,&muertos1);
                pais_getMuertos(pElement2,&muertos2);

                if( (muertos1 > muertosMaximo && muertos2 > muertosMaximo) || flag == 0)
                {
                    flag = 1;

                    if(muertos1>muertos2)
                    {

                    pais_getMuertos(pElement1,&muertosMaximo);
                    paisMaximo = pElement1;


                    }
                    else
                    {
                       pais_getMuertos(pElement2,&muertosMaximo);
                       paisMaximo = pElement2;

                    }

                }
                else if((muertos1 > muertosMaximo && muertos2 < muertosMaximo) || flag == 0)
                {
                    flag = 1;

                    pais_getMuertos(pElement1,&muertosMaximo);
                    paisMaximo = pElement1;

                }
                else if((muertos2 > muertosMaximo && muertos1 < muertosMaximo) || flag == 0)
                {
                    flag = 1;

                    pais_getMuertos(pElement2,&muertosMaximo);
                    paisMaximo = pElement2;

                }
            }
        }

        if(muertosMaximo >0)
        {
            mostrarPais((ePais*)paisMaximo);
            system("pause");

        }





    }



    return retorno;
}
int controller_sortNivelInfeccion(LinkedList* pArrayListPaises)
{
    system("cls");
    int todoOk = 1;
    LinkedList* sortedList = ll_newLinkedList();

    sortedList = ll_clone(pArrayListPaises);

        ll_sort(sortedList,OrdenarPaisByInf,0);

        if(controller_ListPaises(sortedList))
        {

            printf("\nPaises ordeandos con exito.\n\n");
            todoOk = 0;
        }


    return todoOk;
}
int controller_informarMasCastigado(LinkedList* pArrayListPaises)
{
    int flag = 0;
    int retorno = -1;
    ePais* pais = NULL;
    int mayorCantidad;
    void* paisConMasMuertos;
    int muertos;


    if(pArrayListPaises != NULL)
    {
        for(int i=0; i<ll_len(pArrayListPaises); i++)
        {
            pais = (ePais*) ll_get(pArrayListPaises, i);
            pais_getMuertos(pais, &muertos);
            if(flag == 0 || muertos > mayorCantidad)
            {
                    mayorCantidad = muertos;
                    paisConMasMuertos = pais;

                    flag = 1;
                    retorno = 0;
            }
        }

        mostrarPais(paisConMasMuertos);
        printf("Cantidad de muertos: %10d\n", mayorCantidad);
        system("pause");
    }


    return retorno;
}
