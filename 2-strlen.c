#include "shell.h"

/**
 * _strlen - counts the number of characters in a string
 * @s: string parameter
 * Return: return number of characters
 */

int _strlen(char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	return (count);
}
