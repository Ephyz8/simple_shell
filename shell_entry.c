#include "shell.h"
/**
 * main - main entry file into the shell
 *
 * Return: 0 always
 */

int main(int ch, char **ev)
{
        char *pmt = "EphyNeo$ ";
	char *ar[10], *delim = " \n";
        char *buf = NULL;
        size_t bufsz = 0;
        ssize_t num;
	pid_t chd_pid;
        int i, y, status;
        y = 0;
	(void)ch;

        while (1)
        {
                if (isatty(0))
                        shell_print(pmt);

                num = getline(&buf, &bufsz, stdin);

                if (num == -1)
                {
                        /*shell_print("Shell is exiting...\n");*/
                        free(buf);
                        exit(0);
                }

		for (i = 0; buf[i]; i++)
        	{
                	if (buf[i] == '\n')
                        	buf[i] = 0;
        	}

        	ar[y] = strtok(buf, delim);
        	while (ar[y])
        	{
                	ar[++y] = strtok(NULL, delim);
        	}
        	chd_pid = fork();

        	if (chd_pid < 0)
        	{
                	perror("Failed to fork");
                	free(buf);
                	exit(0);
        	}
        	else if (chd_pid == 0)
        	{
                	if (execve(ar[0], ar, ev) == -1)
                        	shell_print("This command does not exists\n");
        	}
        	else
			wait(&status);
                /*shell_print(buf);*/
        }
        free(buf);
        return (0);
}
