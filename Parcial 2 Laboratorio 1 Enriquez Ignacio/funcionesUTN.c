#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcionesUTN.h"


int getInt(int* pAux)
{
    char auxString[400];
    int isOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString); //to integer
        isOk = 0; //exito
    }
    return isOk;
}

int isInt(char *pAux)
{
    int isOk = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }
    while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0; //exito
    }

    return isOk;
}
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max)
{
    int isOk = -1;
    int auxInt;

    if(pEntero != NULL && msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s", msg);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                isOk = 0; //exito
                break;
            }
            else
            {
                system("cls");
                printf("----------------------------------\n");
                printf("%s", msgError);
                printf("----------------------------------\n");
                system("pause");
            }
        }
        while(retry >= 0);
    }
    return isOk;
}
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int isOk = -1;
    float auxFloat;

    if(pFloat != NULL&& msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                isOk = 0; //exito
                break;
            }
            else
            {
                system("cls");
                printf("----------------------------------\n");
                printf("%s", msgError);
                printf("----------------------------------\n");
                system("pause");
            }
        }
        while(retry >= 0);
    }
    return isOk;
}
int getFloat(float* pAux)
{
    char auxString[200];
    int isOk =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString); //to float
        isOk = 0; //exito
    }
    return isOk;
}

int isFloat(char* pAux)
{
    int isOk = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }
    while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0; //exito
    }
    return isOk;
}
int getCadena(char* pAux, int limit)
{
    char auxString[4000];
    int isOk = -1;

    if (pAux != NULL && limit > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux, auxString, limit);
            isOk=0; //exito
        }
    }

    return isOk;
}
int isChar(char str[])
{

    int isOk = 0; //exito

    for(int i = 0; str[i] != '\0'; i++)
    {
        //si no es espacio, si es menor a 'a' o may a 'z', si es men a 'A' o may a 'Z', NO es letra:
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            isOk = -1;
        }
    }

    return isOk;

}
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError)
{
    int isOk = -1;
    char auxString[limit];

    if(pAux != NULL && msg != NULL && msgError != NULL && limit > 0 && retry >= 0)
    {
        do
        {
            printf("%s", msg);

            if(getCadena(auxString, limit) == 0 && isChar(auxString) == 0)
            {
                strncpy(pAux, auxString, limit);
                isOk = 0; //exito
                break;
            }
            else
            {
                system("cls");
                printf("----------------------------------\n");
                printf("%s\n", msgError);
                printf("----------------------------------\n");
                system("pause");
            }
            retry--;

        }
        while(retry>=0);
    }

    return isOk;
}
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo,char maximo, int reintentos)
{
    int retorno = -1;
    char aux;

    if(pResultado != NULL && mensaje!= NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {

        do
        {
            printf("%s",mensaje);
            scanf("%c",&aux);
            if(aux >= minimo && aux <= maximo)
            {
                *pResultado = aux;
                retorno = 0;
                break;
            }
            else
            {
                system("cls");
                printf("----------------------------------\n");
                printf("%s", mensajeError);
                printf("----------------------------------\n");
                system("pause");

            }
        }
        while(reintentos > 0);

    }
    return retorno;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
    int retorno;
    int num;
    while(reintentos>0)
    {
        printf(mensaje);
        if(scanf("%d",&num)==1)
        {
            if(num<=maximo && num>=minimo)
                break;
        }
        fflush(stdin);
        reintentos--;
        printf(mensajeError);
    }
    if(reintentos==0)
    {
        retorno=-1;
    }
    else
    {
        retorno =0;
        *pResultado = num;
    }
    return retorno;
}
