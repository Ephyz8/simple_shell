#include "shell.h"

/**
 * _btcmd - Exits the shell
 * @ar: argument
 * Return: 0
 */

int _btcmd(char **ar)
{
	if (_strcmp(ar[0], "exit") == 0)
	{
		shell_print("Shell is exiting......\n");
			exit(0);
	}
	else if (_strcmp(ar[0], "cd") == 0)
	{
		if (ar[1] == NULL)
		{
			chdir(getenv("HOME"));
		}
		else
			chdir(ar[1]);
	}
	return (0);
}
