#include "shell.h"

/**
 * shell_print - prints to terminal
 * @input: string to be printed
 * Retun: void
 */

void shell_print(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}
