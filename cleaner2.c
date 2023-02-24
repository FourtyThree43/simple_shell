#include "shell.h"

/**
 * cleaner2 - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */
void cleaner2(char **ptr)
{
	for (int i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}
