#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tok.c"

int main(void)
{
	char *arg = NULL;
	char **argv;
	size_t len = 0;
	ssize_t nread;
	pid_t id;
	int status, i;
	
	printf("$ ");
	while((nread = getline(&arg, &len, stdin)) != -1)
	{
		if (strcmp(arg, "exit\n") == 0)
			break;
		arg[nread - 1] = '\0';
		argv = tokenize(arg, " ");
		if ((id = fork()) == -1)
		{
			perror("Error");
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			free(arg);
			exit(EXIT_FAILURE);
		}
		if (id == 0)
		{

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				for (i = 0; argv[i]; i++)
					free(argv[i]);
				free(argv);
				free(arg);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			printf("$ ");
		}
	}
	free(arg);
	exit(EXIT_SUCCESS);
}
