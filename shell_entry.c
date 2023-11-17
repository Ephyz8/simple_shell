#include "shell.h"
/**
 * main - main entry file into the shell
 * @ch: argument
 * @env: enviroment argument
 *
 * Return: 0 always
 */

int main(int ch, char **ev)
{
	int i = 0,y = 0, status;
	pid_t chd_pid;
	ssize_t num;
	size_t bufsz = 0;
	/*bool fppe = false;*/
        char *pmt = "($) ";
	char *ar[] = {NULL, NULL}, *delim = " \n";
        char *buf = NULL, *pth;
        /*y = 0;*/
	(void)ch;

        while (1)
        {
                if (isatty(0))
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
        	ar[y] = strtok(buf, delim);
        	while (ar[y])
        	{
                	ar[++y] = strtok(NULL, delim);
        	}
		ar[y] = NULL;
		pth = _get(ar[0]);
	       if (pth == NULL)
	       {
		       if (_btcmd(ar) != 0)
			       continue;
		       else
			       shell_print("Command does not exist\n");
		      continue;
	       }
		ar[0] = pth;
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
	free(pth);
        return (0);
}
