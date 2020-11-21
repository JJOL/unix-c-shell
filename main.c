#include <stdio.h>
#include "prompt.h"
#include "fileinterpreter.h"

int main(int argc, char *argv[])
{
    if (argc > 2) {
        fprintf(stderr, "%s: usage ./shell [file_name]\n", argv[0]);
        return  -1;
    }

    if (argc == 1) {
        // Execute Prompt
        beginPrompt();
    }

    if (argc == 2) {
        // Execute File Interpreter
        interpretFile(argv[1]);
    }
    
    return 0;
}