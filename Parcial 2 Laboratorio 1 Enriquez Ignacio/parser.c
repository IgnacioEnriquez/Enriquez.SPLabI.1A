#include <stdio.h>
#include <stdlib.h>
#include "paises.h"
#include "string.h"
#include "LinkedList.h"
#include "funcionesUTN.h"
#include "parser.h"
#include "informes.h"
#include "controller.h"


int parser_PaisesFromText(FILE* pFile, LinkedList* pArrayListBicicletas)
{

    ePais* pPais;
    int retorno = -1;
    int r;
    char var1[50];
    char var2[50];
    char var3[50];
    char var4[50];
    char var5[50];

    //if(pFile != NULL && pArrayListEmployee != NULL)
    if(pFile != NULL)
    {


        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do
        {

            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);

            if(r == 5)
            {


                pPais = pais_newParametros(var1,var2,var3,var4,var5);


                if(pPais != NULL)
                {

                    ll_add(pArrayListBicicletas,pPais);
                    retorno = 0;

                }

            }


        }
        while (!feof(pFile));


    }

    free(pPais);

    return retorno;
}
