#ifndef _SHELL_H_
#define _SHELL_H_
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/types.h>
int _strcmp(char *s1, char *s2);
char *_strdup(char *src);
int _btcmd(char **ar);
int _putchar(char input);
char* shell_getline(void);
int shell_print(char *st);
int _delimtr(char chr, char *delim);
char **_strtok(char *stng, char *delim);
char *path_loc(char *pth, char *ar);
char *_get(char *ar);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void prom(char **ch, char **ev);
#endif
