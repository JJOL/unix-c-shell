#ifndef _UTILS_H
#define _UTILS_H

#include <string.h>

void cleanInputStr(char *destStr, char *srcStr)
{
    strcpy(destStr, srcStr);
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


#endif