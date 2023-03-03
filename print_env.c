#include "shell.h"

/**
 * print_env - Prints all the environment variables.
 * @ev: A NULL terminated array of strings containing the environment variables
 *
 * Return: void.
 */
void print_env(char **ev)
{
	unsigned int i;

	for (i = 0; ev[i]; i++)
		_puts(ev[i]), _putchar('\n');
}
