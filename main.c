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
	char *arg = NULL, *ptr = NULL, **argv;
	size_t len = 0;
	ssize_t nread;
	pid_t id;
	int wstatus, status = EXIT_SUCCESS;

	while ((nread = getline(&arg, &len, stdin)) != -1)
	{
		if (_strspn(arg, " \n\r\t\a") == strlen(arg))
		{
			free(arg), arg = NULL;
			continue;
		}
		if (_strcmp(arg, "exit\n") == 0)
			break;
		arg[nread - 1] = '\0';
		argv = tokenize(arg, " ");
		id = fork();
		if (id == -1)
			perror(av[0]), free_error(argv, arg);
		if (id == 0)
		{
			ptr = NULL;
			if (argv[0][0] != '/')
				ptr = find_in_path(argv[0]);
			if (ptr == NULL)
				ptr = argv[0];
			if (execve(ptr, argv, ev) == -1)
				perror(av[0]), free_error(argv, arg);
		}
		else
		{
			wait(&wstatus);
			if (WIFEXITED(wstatus))
				status = WEXITSTATUS(wstatus);
			free_tok(argv);
		}
	}
	free(arg), exit(status);
}
