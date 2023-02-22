#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "temp/tok.c"
#include "temp/string1.c"
#include "temp/string.c"

void _error(char ***argv, char **arg);

/**
 * main - implements a simple shell
 * @ac: argument count
 * @av: argument vector
 * @ev: environment
 *
 * Return: EXIT_SUCCESS.
 */
int main(int ac __attribute__((unused)), char **av, char **ev)
{
	char *arg = NULL;
	char **argv;
	size_t len = 0;
	ssize_t nread;
	pid_t id;
	int status, i;

	_puts("$ ");
	while ((nread = getline(&arg, &len, stdin)) != -1)
	{
		if (_strcmp(arg, "exit\n") == 0)
			break;
		arg[nread - 1] = '\0';
		argv = tokenize(arg, " ");
		id = fork();
		if (id == -1)
		{
			perror(av[0]);
			_error(&argv, &arg);
		}
		if (id == 0)
		{

			if (execve(argv[0], argv, ev) == -1)
			{
				perror(av[0]);
				_error(&argv, &arg);
			}
		}
		else
		{
			wait(&status);
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			_puts("$ ");
		}
	}
	free(arg);
	exit(EXIT_SUCCESS);
}

/**
 * _error - frees alloc'd pointers following system error
 * @argv: pointer to a pointer to an array of pointers
 * @arg: pointer to a pointer to an array of characters
 *
 * Return: void.
 */
void _error(char ***argv, char **arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}
