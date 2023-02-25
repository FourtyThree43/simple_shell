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
	char **argv = NULL;
	char temp[120];
	char bin[6] = "/bin/";
	size_t len = 0;
	ssize_t nread;
	pid_t id;
	int status, i;

	_memset(temp, 0, 120);
	_puts("$ ");
	while ((nread = getline(&arg, &len, stdin)) != -1)
	{
		if (_strcmp(arg, "\n") == 0)
		{
			free(arg);
			arg = NULL;
			_puts("$ ");
			continue;
		}
		if (_strcmp(arg, "exit\n") == 0)
			free(arg), exit(EXIT_SUCCESS);
		arg[nread - 1] = '\0';
		if (arg[0] != '/')
		{
			_strcpy(temp, arg);
			arg = realloc(arg, _strlen(temp) + 6);
			_memset(arg, 0, _strlen(arg) + 1);
			arg = _strcat(bin, temp);
		}
		argv = tokenize(arg, " ");
		if (!argv)
		{
			free(arg);
			dprintf(2, "Error parsing commands\n");
			_puts("$ ");
			continue;
		}
		id = fork();
		if (id == -1)
			perror(av[0]);
		if (id == 0)
		{
/*			if (_strcmp(arg, "env") == 0)
				printenviron(ev), exit(EXIT_SUCCESS);
*/			if (execve(argv[0], argv, ev) == -1)
				perror(av[0]), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			for (i = 0; argv[i]; i++)
			{
				free(argv[i]);
				argv[i] = NULL;
			}
			free(argv);
			free(arg);
			argv = NULL;
			arg = NULL;
			_puts("$ ");
		}
	}
	free(arg);
	_putchar('\n');
	exit(EXIT_SUCCESS);
}
