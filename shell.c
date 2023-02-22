#include "shell.h"

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
			perror(av[0]), _error(&argv, &arg);
		if (id == 0)
		{
			if (_strcmp(arg, "env") == 0)
				printenviron(), exit(1);
			if (execve(argv[0], argv, ev) == -1)
				perror(av[0]), _error(&argv, &arg);
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
