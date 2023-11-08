#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
int _putchar(char input);
int shell_print(char *st);
int main(int ch, char **ev);
#endif
