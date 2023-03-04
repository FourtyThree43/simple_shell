#include "shell.h"

/**
 * get_input - Read the line of input from user.
 *
 * Return: Pointer to a buffer conatining the user's input.
*/
char *get_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nread;

	do {
		/* print shell prompt */
		prompt();

		/* get a line of input from user */
		nread = getline(&input, &input_size, stdin);

		/* check for EOF or error */
		if (nread == -1)
		{
			free(input);
			return (NULL);
		}

		/* remove trailing newline character */
		input[nread - 1] = '\0';

	} while (input[0] == '\0' || isspace(input[0]));

	return (input);
}
