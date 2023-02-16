#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - run a program in 5 child processes of same parent
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	pid_t pid;
	int i, status;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork() error");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			char *argv[] = {"hello", NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve() error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}

	if (pid != 0)
		exit(EXIT_SUCCESS);
}
