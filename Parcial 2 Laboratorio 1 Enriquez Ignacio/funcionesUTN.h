#ifndef FUNCIONESUTN_H_INCLUDED
#define FUNCIONESUTN_H_INCLUDED

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo,char maximo, int reintentos);

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

int isChar(char str[]);

int getCadena(char* pAux, int limit);

int isFloat(char* pAux);

int getFloat(float* pAux);

int isInt(char *pAux);

int getInt(int* pAux);


#endif // FUNCIONESUTN_H_INCLUDED
