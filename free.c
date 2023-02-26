#include "shell.h"

/**
 * free_error - frees alloc'd pointers following system error
 * @argv: pointer to a pointer to an array of pointers
 * @arg: pointer to a pointer to an array of characters
 *
 * Return: void.
 */
void free_error(char **argv, char *arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * free_tok - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */
void free_tok(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free(ptr[i]), ptr[i] = NULL;
	free(ptr);
	ptr = NULL;
}
