#include <unistd.h>
#include <stdlib.h>
#include "logging.h"
#include "wait.h"

int countArguments(char **argv)
{
    int count = 0;
    while ( *(argv + count) != (char *)0 ) count++;
    return count;
}

int spawnProcess(char *name, char **argv)
{
    // Agregar puntero nulo
    int argc = countArguments(argv);
    char *argvExt[argc + 1];
    int i;
    for (i = 0; i < argc; i++) {
        printf("%d: ", i);
        printf("Copying argv[%d] = '%s'\n", i, argv[i]);
    //     argvExt[i] = argv[i];
    }
    // printf("Assigning argvExt[%d] = 0\n", i);
    // argvExt[i] = (char *)0;

    // i = 0;
    // while (argvExt[i] != (char *)0) printf("(%s)\n", argvExt[i++]);
    // printf("Done with extension\n");
    
    // int pid;

    // if ((pid = vfork()) < 0) {
    //     KERNEL_ERROR("Could not spawn process!")
    //     return -1;
    // } else if (pid == 0) {
    //     if (execvp(name, argvExt) < 0) {
    //         KERNEL_ERROR("Could not spawn program specified!")
    //         return -2;
    //     }
    // } else {
    //     //printf("Process '%s' spawned!\n", name);
    //     waitpid(pid, NULL, 0);
    // }

    return 0;
}
