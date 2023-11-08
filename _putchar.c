#include "shell.h"

/**
 * _putchar - prints to terminal
 * @input: string to be printed
 * Return: string
 */

int _putchar(char input)
{
	return (write(1, &input, 1));
	/*write(STDOUT_FILENO, input, strlen(input));*/
}
