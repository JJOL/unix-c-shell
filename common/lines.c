#include <string.h>
#include <stdio.h>

int cleanWhiteSpaces(char *outStr, const char *inStr)
{
    char inStrCpy[strlen(inStr) + 1];
    strcpy(inStrCpy, inStr);

    const char delimiters[] = " ";
    char *token = strtok(inStrCpy, delimiters);
    int i = 0;
    while (token != NULL) {
        printf("%d: [%s]\n", ++i, token);

        token = strtok(NULL, delimiters);
    }

    return 1;
}