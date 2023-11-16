#include "shell.h"

/**
 * _delimtr - checks if character is a delimeter
 * @chr: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int _delimtr(char chr, char *delim)
{
	while (*delim)
		if (*delim++ == chr)
			return (1);
	return (0);
}
