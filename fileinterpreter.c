#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "common/constants.h"
#include "common/logging.h"
#include "common/kernel.h"
#include "fileinterpreter.h"

void interpretFile(char *fName)
{
    int fd, nBytesRead, linePos;
    char buff[1], lineStr[MAX_LINE_LEN];

    if ((fd = open(fName, O_RDONLY)) < 0) {
        USER_ERROR("Could not open specified file!")
        exit(-1);
    }

    linePos = 0;
    while ((nBytesRead = read(fd, buff, 1)) > 0) {
        if (buff[0] == '\n' || buff[0] == '\r') {
            lineStr[linePos] = '\0';
            kernelLine(lineStr);
            linePos = 0;
        } else {
            lineStr[linePos++] = buff[0];
        }
    }

    // Execute to clean last segment without \n
    lineStr[linePos] = '\0';
    kernelLine(lineStr);


    close(fd);
}