#include "shell.h"

/**
 * shell_print - prints to terminal
 * @st: string to be printed
 * Return: string
 */

int shell_print(char *st)
{
	int i = 0, cnt = 0;

	while (st[i])
	{
		cnt = cnt + _putchar(st[i++]);
	}
	return (cnt);
}
