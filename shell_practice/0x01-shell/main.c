#include "shell.h"

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		print_prompt(); /*Display prompt to the user */
		line = read_line(); /*Read user input */
		args = parse_line(line); /* Parse the user input */
		status = execute(args); /* Execute the command */

		free(line);
		free(args);
	} while (status);

	return (0);
}
