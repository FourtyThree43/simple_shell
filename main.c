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
	char *input;
	char **args;
	int status;

	/* Register signal handlers */
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		input = get_input();
		if (!input || !*input)/* EOF detected, exit the loop */
			break;

		args = tokenize_input(input);
		if (!args || !*args)
		{
			free(input);
			free_tokens(args);
			continue;
		}
		status = execute(args);
		free(input);
		free_tokens(args);

		/* Set status to 1 to continue the loop */
		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}
