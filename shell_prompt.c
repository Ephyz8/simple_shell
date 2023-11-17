#include "shell.h"
/**
 * prom - main entry file into the shell
 * @ch: argument
 * @ev: enviroment argument
 */

void prom(char **ch, char **ev)
{
        char *pmt = "($) ";
	char *ar[] = {NULL, NULL}; 
        char *buf = NULL; 
        size_t bufsz = 0;
        ssize_t num;
	pid_t chd_pid;
        int i = 0, status;

        while (1)
        {
		if (isatty(STDIN_FILENO))
			shell_print(pmt);
                num = getline(&buf, &bufsz, stdin);
                if (num == -1)
                {
                        free(buf);
                        exit(EXIT_FAILURE);
                }
		while (buf[i])
		{
			if (buf[i] == '\n')
                        	buf[i] = 0;
			i++;
        	 }
		ar[0] = buf;
        	chd_pid = fork();
        	if (chd_pid < 0)
        	{
                	shell_print("Failed to fork");
                	free(buf);
                	exit(EXIT_FAILURE);
        	}
        	else if (chd_pid == 0)
        	{
                	if (execve(ar[0], ar, ev) == -1)
                        	shell_print("This command does not exists\n");
			exit(1);
        	}
      	 	else
			wait(&status);
	}
}
