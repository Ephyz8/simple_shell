#include "shell.h"

/**
 * _strdup - duplicates a string
 * @src: string to be duplicated
 * Return: string
 */

char *_strdup(char *src)
{
	size_t len;
	char *dest;

	if (src == NULL)
	{
		return (NULL);
	}
	len = _strlen(src);
	dest = (char *)malloc(len + 1);

	if (dest == NULL)
	{
		return (NULL);
	}

	_strcpy(dest, src);
	return (dest);
}
