#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prompt.h"
#include "common/kernel.h"
#include "common/utils.h"

#define MAX_LINE_LEN 64
#define MAX_PS1_LEN  12
#define EXIT_CMD "exit"
#define PS1_CMD "PS1="

char ps1[MAX_PS1_LEN];
int running;

void beginPrompt()
{
    char rawLineStr[MAX_LINE_LEN];
    int rawLineStrLen;

    // Init Shell Settings and props
    running = 1;
    strcpy(ps1, "SuperSHELL");

    printf("Welcome to the CLI Prompt!\n");
    do {
        printf("%s> ", ps1);

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
    return -1;
}


void cmdPS1(char *lineStr)
{
    getVal(lineStr, ps1);
}