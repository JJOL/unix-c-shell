#include "constants.h"
#include "logging.h"
#include "kernel.h"
#include "utils.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int spawnProcess(char *name, char **argv);



void kernelLine(char *lineStr)
{
    // separate invoc commands
    // for each invoc command 
    //    execute invoc command

    // Break Command into command arguments and spawn
    char *eArgs[MAX_LINE_LEN];
    splitStr(eArgs, lineStr, " ");
    spawnProcess(eArgs[0], eArgs);
}

int spawnProcess(char *name, char **argv)
{
    int pid;
    if ((pid = vfork()) < 0) {
        KERNEL_ERROR("Could not vfork()!");
        //fprintf(stderr, "%s: Could not vfork()!\n", "KERNEL_ERROR");
    } else if (pid == 0) {
        execvp(name, argv);
        fprintf(stderr, "%s: Could not exec(%s)!\n", "KERNEL_ERROR", name);
        _exit(-1);
    } else {
        waitpid(pid, NULL, 0);
    }
}