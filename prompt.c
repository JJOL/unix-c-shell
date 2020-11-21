/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final - UNIX C Shell

* Fecha: 21-Nov-2020

* Autor: A01702832 Juan Jose Olivera Loyola

* Modulo: promph.h

* Descripcion: Implementacion de la funciones usadas para el shell interactivo

*

*--------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "prompt.h"
#include "common/kernel.h"
#include "common/utils.h"
#include "common/constants.h"
#include "common/logging.h"

char ps1[MAX_PS1_LEN];
char dirPath[PATH_MAX];
int running;

void beginPrompt()
{
    char rawLineStr[MAX_LINE_LEN];
    int rawLineStrLen;

    // Init Shell Settings and props
    running = 1;
    strcpy(ps1, "SuperSHELL");
    getcwd(dirPath, PATH_MAX);

    printf("Welcome to the CLI Prompt!\n");
    do {
        
        printf(C_R"%s"C_RST":"C_Y"%s"C_RST"> ", ps1, dirPath);

        // Get Input Line and remove \n
        fgets(rawLineStr, MAX_LINE_LEN, stdin);
        rawLineStrLen = strlen(rawLineStr);
        rawLineStr[rawLineStrLen-1] = '\0';

        processLine(rawLineStr);
    } while (running);

}

void endPrompt()
{
    exit(0);
}

void processLine(char *lineStr)
{
    char cleanedLineStr[MAX_LINE_LEN];

    // clean string
    cleanInputStr(cleanedLineStr, lineStr); // utils.h

    // try to run shell commands
    if (shellCmd(cleanedLineStr) < 0) {
        kernelLine(cleanedLineStr);         // kernel.h
    }

}

int shellCmd(char *lineStr)
{
    // First of all check if is exit
    if (strcmp(EXIT_CMD, lineStr) == 0)
        endPrompt();
    else if (strncmp(PS1_CMD, lineStr, strlen(PS1_CMD)) == 0) {
        cmdPS1(lineStr);
        return 0;
    }
    else if (strncmp(CD_CMD, lineStr, strlen(CD_CMD)) == 0) {
        cmdCD(lineStr);
        return 0;
    }
    return -1;
}


void cmdPS1(char *lineStr)
{
    getVal(lineStr, ps1);
}

void cmdCD(char *lineStr)
{
    char relPath[MAX_LINE_LEN];
    int offset, i;

    offset = strlen(CD_CMD) + 1;
    i = 0;
    do {
        relPath[i] = lineStr[offset + i];
        i++;
    } while (lineStr[i] != '\0');

    if (chdir(relPath) < 0) {
        USER_ERROR("Can not cd into specified path!")
        return;
    }

    getcwd(dirPath, PATH_MAX);
}