/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final - UNIX C Shell

* Fecha: 21-Nov-2020

* Autor: A01702832 Juan Jose Olivera Loyola

* Modulo: promph.h

* Descripcion: Definicion de la funciones usadas para el shell interactivo

*

*--------------------------------------------------------------*/
#ifndef _PROMPT_H
#define _PROMPT_H
void beginPrompt();
void processLine(char *lineStr);
int shellCmd(char *lineStr);
void cmdPS1(char *lineStr);
void cmdCD(char *lineStr);
#endif