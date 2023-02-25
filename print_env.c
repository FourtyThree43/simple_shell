#include "shell.h"

/**
 * print_env - print the current environment
 * @ev: smth.
 * Return: void.
 */
void print_env(char **ev)
{
	unsigned int i;

	for (i = 0; ev[i]; i++)
		_puts(ev[i]), _putchar('\n');
}
