/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final - UNIX C Shell

* Fecha: 21-Nov-2020

* Autor: A01702832 Juan Jose Olivera Loyola

* Modulo: utils.h

* Descripcion: Definicion de funciones de utileria de string de comandos

*

*--------------------------------------------------------------*/
#ifndef _UTILS_H
#define _UTILS_H
void cleanInputStr(char *destStr, char *srcStr);
void splitStr(char **list, char *str, const char *DELIMITERS);
void getVal(char *str, char* val);
int countArguments(char **args);
#endif