/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final - UNIX C Shell

* Fecha: 21-Nov-2020

* Autor: A01702832 Juan Jose Olivera Loyola

* Modulo: logging.h

* Descripcion: Macros de utileria para loggeo

*

*--------------------------------------------------------------*/
#ifndef _LOGGING_H
#define _LOGGING_H
#include <stdio.h>
#define OUT_ERROR(code, msg) fprintf(stderr, "%s: %s\n", code, msg);
#define USER_ERROR(msg) OUT_ERROR("InvalidInput", msg)
#define KERNEL_ERROR(msg) OUT_ERROR("OSKernelError", msg)
#endif