#include "shell.h"


char *shell_getline(void)
{
	static char buf[BUFFER_SIZE];
	static int ps = 0, nbytes = 0;
	char *line = NULL, *nline;
	int len = 0, i, rem;
	int bufempty = 1;
	char a;
	
	while (1) 
	{
		if (bufempty) 
		{
			nbytes = read(STDIN_FILENO, buf, BUFFER_SIZE);
			if (nbytes <= 0)
			return (NULL);
		}
		bufempty = 0;
		ps = 0;
	}
	
	a  = buf[ps++];
        len++;
	
	if (a == '\n' || a == '\0')
	{
		nline = (char*)malloc(len);
		if (nline == NULL)
		{
			perror("Error in memory allocation");
			exit(1);
		}
		for (i = 0; i < len; i++)
		{
			nline[i] = buf[i - len + ps];
		}
		nline[len - 1] = '\0';
		rem = nbytes - ps;
		for (i = 0; i < rem; i++)
		{
			buf[i] = buf[i + ps];
		}
		ps = 0;
		nbytes = rem;
		bufempty = 1;
		return (nline);
	
		if (len % BUFFER_SIZE == 0)
		{
			nline = (char*)malloc(len + BUFFER_SIZE);
			if (nline == NULL)
			{
				perror("Memory allocation error");
				exit(1);
			}
			for (i = 0; i < len; i++)
			{
				nline[i] = line[i];
			}
			free(line);
			line = nline;
		}

	}
	return (0);
}
