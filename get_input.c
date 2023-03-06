#include "shell.h"

static char *last_input;
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
		/*prompt();*/

		/* get a line of input from user */
		nread = getline(&input, &input_size, stdin);

		/* check for EOF or error */
		if (nread == -1)
		{
			free(input);
			/*_puts("\n");*/
			return (NULL);
		}

		/* remove trailing newline character */
		input[nread - 1] = '\0';

	} while (input[0] == '\0' || isspace(input[0]));

	/* update last_input to point to the new input */
	last_input = input;
	return (input);
}

/**
 * free_last_input - Frees the most recent input entered by the user.
 *
 * This function frees the memory allocated for the most recent input string
 * entered by the user. It should be called after the input string is no longer
 * needed.
 */
void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
