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
	char *arg = NULL, *ptr = NULL, **argv = NULL;
	const char	*path;
	size_t len = 0;
	ssize_t nread;
	pid_t id;
	int wstatus, status = EXIT_SUCCESS;

	path = _getenv("PATH");
	printf(PROMPT);
	while ((nread = getline(&arg, &len, stdin)) != -1)
	{
		if (strspn(arg, " \n\r\t\a") == strlen(arg))
		{
			printf(PROMPT);
			continue;
		}
		if (strcmp(arg, "exit\n") == 0)
			break;
		arg[nread - 1] = '\0';
		argv = tokenize(arg, " ");
		ptr = which(argv[0], path);
		if (ptr == NULL)
		{
			printf("%s: command not found\n%s", argv[0], PROMPT);
			free_tok(argv);
			continue;
		}
		free(argv[0]);
		argv[0] = ptr;
		id = fork();
		if (id == -1)
		{
			perror(av[0]);
			free_error(argv, arg);
		}
		if (id == 0)
		{
			if (execve(argv[0], argv, ev) == -1)
			{
				perror(av[0]);
				free_error(argv, arg);
			}
		}
		else
		{
			wait(&wstatus);
			if (WIFEXITED(wstatus))
				status = WEXITSTATUS(wstatus);
			free_tok(argv);
			printf(PROMPT);
		}
	}
	if (strcmp(arg, "exit\n") != 0)
		putchar(10);
	free(arg);
	exit(status);
}
