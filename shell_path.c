#include "shell.h"

/**
 * path_loc - func. to locate an executable in PATH
 * @pth: File Path
 * @ar: Path argument
 * Return: 0
 */

char *path_loc(char *pth, char *ar)
{
	char *pth_cy, *pthTkn, *flePth;
	char *delim = ":"; 
	/*char *buf;*/

	pth_cy = _strdup(pth);
	pthTkn = strtok(pth_cy, delim);

	flePth = malloc(_strlen(ar) + _strlen(pthTkn) + 2);

	while (pthTkn != NULL)
	{

		_strcpy(flePth, pthTkn);
		_strcat(flePth, "/");
		_strcat(flePth, ar);
		_strcat(flePth, "\0");

		if (access(flePth, X_OK) == 0)
		{
			free(pth_cy);
			return (flePth);
		}
		pthTkn = strtok(NULL, delim);
	}
	free(flePth);
	free(pth_cy);

	/*if (stat(ar, &buf) == 0)*/
		/*return (ar);*/
	return (NULL);
}

/**
 * _get - func that gets the PATH
 * @ar: argument
 * Return: path
 */

char *_get(char *ar)
{
	char *pth, *fullPth;

	pth = getenv("PATH"); 

	if (pth)
	{
		fullPth = path_loc(pth, ar);
		return (fullPth);
	}
	return (NULL);
}
