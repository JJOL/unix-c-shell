#ifndef _PROMPT_H
#define _PROMPT_H
void beginPrompt();
void processLine(char *lineStr);
int shellCmd(char *lineStr);
void cmdPS1(char *lineStr);
#endif