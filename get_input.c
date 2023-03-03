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

	/* print shell prompt */
	prompt();

	/* Get a line of input from user */
	nread = getline(&input, &input_size, stdin);

	//* Check for EOF or error */
	if (nread == -1)
		return (NULL);

	/* if the user enter a white space, return NULL */
	if (nread != -1 && isspace(input[0]))
	{
		free(input);
		return (NULL);
	}

	/* Removes traling \n charater */
	input[nread - 1] = '\0';

	return (input);
}
