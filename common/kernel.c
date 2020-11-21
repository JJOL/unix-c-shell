/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final - UNIX C Shell

* Fecha: 21-Nov-2020

* Autor: A01702832 Juan Jose Olivera Loyola

* Modulo: kernel.c

* Descripcion: Implementacion del kernel para procesar linea de comandos

*

*--------------------------------------------------------------*/
#include "constants.h"
#include "logging.h"
#include "kernel.h"
#include "utils.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>

int spawnProcesses(char **batches, int n);
int spawnProcess(char *cmdLine);


void kernelLine(char *lineStr)
{
    // separate invoc commands
    // for each invoc command 
    //    execute invoc command
    char *batches[MAX_LINE_LEN];
    int n, i;

    splitStr(batches, lineStr, ";");
    n = countArguments(batches);

    spawnProcesses(batches, n);

}

int spawnProcess(char *cmdLine)
{
    int pid;

    char *eArgs[MAX_LINE_LEN];
    splitStr(eArgs, cmdLine, " ");

    if ((pid = fork()) < 0) {
        KERNEL_ERROR("Could not fork()!");
        return -1;
    } else if (pid == 0) {
        execvp(eArgs[0], eArgs);
        fprintf(stderr, "%s: Could not exec(%s)!\n", "KERNEL_ERROR", eArgs[0]);
        _exit(-1);
    } else {
        return pid;
    }
}

int spawnProcesses(char **batches, int n)
{
    int pids[n], pid;
    int i;
    char cleanedLine[MAX_LINE_LEN];

    int quitAfter = 0;

    for (i = 0; i < n; i++) {

        cleanInputStr(cleanedLine, batches[i]);
        if (strlen(cleanedLine) == 0) {
            printf("Warning: Found an empty command! Ignoring it...\n");
            continue;
        }
        
        
        // printf("Executing '%s'...\n", cleanedLine);

        if (strcmp("quit", cleanedLine) == 0) {
            quitAfter = 1;
            continue;
        }

        pids[i] = spawnProcess(cleanedLine);
    }

    for (i = 0; i < n; i++) {
        if (pids[i] != -1) waitpid(pids[i], NULL, 0);
    }

    if (quitAfter) {
        // Terminate kernel and shell
        exit(0);
    }
}