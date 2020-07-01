#include <stdio.h>
#include <stdlib.h>
#include "paises.h"
#include "string.h"
#include "LinkedList.h"
#include "funcionesUTN.h"
#include "parser.h"
#include "informes.h"
#include "controller.h"


ePais* paises_new()
{
    ePais* nuevoPais = (ePais*) malloc(sizeof(ePais));

    if(nuevoPais != NULL)
    {
        nuevoPais ->id = 0;
        nuevoPais ->infectados = 0;
        nuevoPais ->muertos = 0;
        nuevoPais ->recuperados = 0;
        strcpy(nuevoPais ->nombre, " ");

    }

    return nuevoPais;
}

ePais* pais_newParametros(char* idStr,char* nombreStr,char* infectadosStr,char* recuperadosStr,char* muertosStr)
{

    ePais*  nuevoPais = paises_new();

    if(nuevoPais != NULL)
    {
        if(pais_setId(nuevoPais, atoi(idStr)) == 0)
        {

            if(pais_setNombre(nuevoPais, nombreStr) == 0)
            {

                if(pais_setInfectados(nuevoPais,atoi(infectadosStr)) == 0)
                {

                    if(pais_setRecuperados(nuevoPais,atoi(recuperadosStr)) == 0)
                    {

                        if(pais_setMuertos(nuevoPais,atoi(muertosStr)) == 0)
                        {

                            //Si llega a este punto se le asignaron todos los campos,sino los campos quedan en 0 gracias al new_bicicleta

                        }

                    }

                }
            }

        }
    }

    return nuevoPais;
}

int pais_setId(ePais* pais,int id)
{
    int retorno = -1;

    if( pais != NULL && id >= 0)
    {
        pais ->id = id;
        retorno = 0;
    }

    return retorno;

}

int pais_setRecuperados(ePais* pais,int recuperados)
{
    int retorno = -1;

    if( pais != NULL && recuperados >= 0)
    {
        pais ->recuperados = recuperados;
        retorno = 0;
    }

    return retorno;

}

int pais_setInfectados(ePais* pais,int infectados)
{
    int retorno = -1;

    if( pais != NULL && infectados >= 0)
    {
        pais ->infectados = infectados;
        retorno = 0;
    }

    return retorno;

}

int pais_setMuertos(ePais* pais,int muertos)
{
    int retorno = -1;

    if( pais != NULL && muertos >= 0)
    {
        pais ->muertos = muertos;
        retorno = 0;
    }

    return retorno;

}

int pais_setNombre(ePais* pais,char* nombre)
{
    int retorno = -1;

    if( pais != NULL && strlen(nombre) >= 2 && strlen(nombre) < 20)
    {
        strcpy(pais ->nombre, nombre);
        retorno = 0;

    }

    return retorno;
}


int pais_getId(ePais* pais,int* id)
{
    int retorno = -1;

    if(pais != NULL && id != NULL)
    {
        *id = pais ->id;
        retorno = 0;
    }

    return retorno;

}

int pais_getRecuperados(ePais* pais,int* recuperados)
{
    int retorno = -1;

    if(pais != NULL && recuperados != NULL)
    {
        *recuperados = pais ->recuperados;
        retorno = 0;
    }

    return retorno;

}

int pais_getNombre(ePais* pais,char* nombre)
{
    int retorno = 1;

    if(pais != NULL && nombre != NULL)
    {
        strcpy(nombre, pais->nombre);
        retorno = 0;
    }

    return retorno;

}

int pais_getInfectados(ePais* pais,int* infectados)
{
    int retorno = -1;

    if(pais != NULL && infectados != NULL)
    {
        *infectados = pais ->infectados;
        retorno = 0;
    }

    return retorno;

}

int pais_getMuertos(ePais* pais,int* muertos)
{
    int retorno = -1;

    if(pais != NULL && muertos != NULL)
    {
        *muertos = pais ->muertos;
        retorno = 0;
    }

    return retorno;

}

int mostrarPais( ePais* pais)
{
    int retorno = -1;

    if( pais != NULL)
    {
        retorno = 0;
        printf(" %3d        %20s           %5d      %5d         %5d \n",pais ->id, pais ->nombre, pais ->recuperados, pais -> infectados, pais ->muertos);


    }
    return retorno;

}

int mostrarPaises(LinkedList* pArrayListPaises)
{
    int retorno = -1;
    int tam;
    int flag = 0;
    ePais* auxPais;


    if(pArrayListPaises != NULL)
    {
        tam = ll_len(pArrayListPaises);
        retorno = 0;
        printf(" Id                   Nombre          Recuperados     Infectados     Muertos\n");

        for(int i = 0; i < tam ; i++ )
        {
            auxPais = (ePais*) ll_get(pArrayListPaises,i) ;

            if(auxPais !=  NULL )
            {

                mostrarPais(auxPais);
                flag = 1;

            }
        }


        if (flag== 0)
        {
            printf("No hay Paises\n\n");
        }
        printf(" \n\n");


    }
    return retorno;
}

int filtroPaisesExitosos(void* x)
{
	int ordenDevuelto;
	int muertos;

	pais_getMuertos(x,&muertos);



	if(muertos < 5000)
	{

		ordenDevuelto = 1;

	}
	else
	{

		ordenDevuelto = 0;

	}

	return ordenDevuelto;
}

int filtroPaisesAlHorno(void* x)
{
	int ordenDevuelto;
	int recuperados;
	int infectados;

	pais_getRecuperados(x,&recuperados);
	pais_getInfectados(x,&infectados);



	if(infectados  > (recuperados*3))
	{

		ordenDevuelto = 1;

	}
	else
	{

		ordenDevuelto = 0;

	}

	return ordenDevuelto;
}

void* assignEstadisticas(void* x)
{
    ePais* auxPais = NULL;
    int aleatorioRecup= rand()%(50001+950000);
    int aleatorioInf = rand()%(40001+1960000);
    int aleatorioMuertos = rand()%(1001+50000);

    if(auxPais == NULL)
    {
        auxPais = (ePais*) x;
        pais_setRecuperados(auxPais,aleatorioRecup);
        pais_setInfectados(auxPais,aleatorioInf);
        pais_setMuertos(auxPais,aleatorioMuertos);
    }


    return auxPais;
}

int OrdenarPaisByInf(void* x, void* y)
{
	int ordenDevuelto = 0;
	int primerInfect;
	int segundoInfect;

	pais_getInfectados(x,&primerInfect);
	pais_getInfectados(y,&segundoInfect);


	if(primerInfect>segundoInfect)
	{

		ordenDevuelto = 1;

	}
	else if(primerInfect<segundoInfect)
	{

		ordenDevuelto = -1;

	}



	return ordenDevuelto;
}
