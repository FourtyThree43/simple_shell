#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {NULL, NULL};
	size_t len = 0;
	ssize_t nread;
	pid_t id;
	int status;
	
	printf("$ ");
	while((nread = getline(&(argv[0]), &len, stdin)) != -1)
	{
		if (strcmp(argv[0], "exit\n") == 0)
			break;
		if ((id = fork()) == -1)
		{
			perror("Error (fork)");
			exit(EXIT_FAILURE);
		}
		if (id == 0)
		{
			(argv[0])[nread - 1] = '\0';

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error (execve)");
				free(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			free(argv[0]);
			argv[0] = NULL;
			printf("$ ");
		}
	}
	free(argv[0]);
	exit(EXIT_SUCCESS);
}
