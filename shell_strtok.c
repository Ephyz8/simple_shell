#include "shell.h"

/**
 * _strtok - splits a string into words. Repeat delimiters are ignored
 * @stng: input string
 * @delim: delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtok(char *stng, char *delim)
{
	char **tc;
	int num = 0, a, b, c, d;

	if (stng == NULL || stng[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (a = 0; stng[a] != '\0'; a++)
		if (!_delimtr(stng[a], delim) && (_delimtr(stng[a + 1], delim) || !stng[a + 1]))
			num++;

	if (num == 0)
		return (NULL);
	tc = malloc((1 + num) * sizeof(char *));
	if (!tc)
		return (NULL);
	for (a = 0, b = 0; b < num; b++)
	{
		while (_delimtr(stng[a], delim))
			a++;
		c = 0;
		while (!_delimtr(stng[a + c], delim) && stng[a + c])
			c++;
		tc[b] = malloc((c + 1) * sizeof(char));
		if (!tc[b])
		{
			for (c = 0; c < b; c++)
				free(tc[c]);
			free(tc);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			tc[b][d] = stng[a++];
		tc[b][d] = 0;
	}
	tc[b] = NULL;
	return (tc);
}
