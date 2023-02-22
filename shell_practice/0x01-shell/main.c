#include "shell.h"

/**
 * main - Entry point for the shell
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	char *line; /* Initialize to NULL */
	char **args; /* Initialize to NULL */
	int status = 1;
	size_t bufsize = 0;

	while (status)
	{
		print_prompt();
		if (getline(&line, &bufsize, stdin) == -1) /* Check for EOF or error */
		{
			free(line);
			break;
		}
		args = tokenize(line, " \n\r\t\a");
		if (args == NULL || *args == NULL) /* Check for empty line */
		{
			free_tokens(args);
			continue;
		}
		status = execute(args, get_path(environ));
		free_tokens(args);
	}

	free(line); /* Free memory used for input line */

	return (0);
}
