#include "utils.h"
#include <string.h>


/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final - UNIX C Shell

* Fecha: 21-Nov-2020

* Autor: A01702832 Juan Jose Olivera Loyola

* Modulo: utils.c

* Descripcion: Implementacion de funciones de utileria de string de comandos
*

*--------------------------------------------------------------*/#include <stdio.h>

void cleanInputStr(char *destStr, char *srcStr)
{
    int srcLen;
    int si, di;

    srcLen = strlen(srcStr);
    si = 0;
    di = 0;

    // Saltar espacios iniciales
    while (srcStr[si] == ' ' || srcStr[si] == '\t') si++;

    // Quitar duplicados
    for (; si < srcLen; si++) {
        if (si > 0) {
            if (srcStr[si] == ' ' && srcStr[si-1] == ' ') continue;
            if (srcStr[si] == '\t' && srcStr[si-1] == '\t') continue;
        }
        destStr[di++] = srcStr[si];
    }
    
    // Remover espacios final
    do {
        di--;
    } while (destStr[di] == ' ' || destStr[di] == '\t');

    destStr[++di] = '\0';
}

void getVal(char *str, char* val)
{
    const char SEP[] = "=";
    char *token;
    char strCpy[strlen(str)];
    strcpy(strCpy, str);


    token = strtok(strCpy, SEP);
    // Esta es la variable
    if (token == NULL) { return; } // NO HAY VARIABLE

    token = strtok(NULL, SEP); // Valor
    if (token == NULL) { return; } // NO HAY VALOR

    strcpy(val, token);
}

void splitStr(char **list, char *str, const char *DELIMITERS)
{
    char *token;
    int i;

    i = 0;
    token = strtok(str, DELIMITERS);
    list[i++] = token;
    
    do {
        token = strtok(NULL, DELIMITERS);
        list[i++] = token;
    } while(token != NULL);
}

int countArguments(char **list)
{
    int count;
    count = 0;

    while (list[count] != NULL) count++;

    return count;
}