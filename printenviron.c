#include "shell.h"

/**
 * printenviron - print the current environment
 * @ev: smth.
 * Return: void.
 */
void printenviron(char **ev)
{
	unsigned int i;

	for (i = 0; ev[i]; i++)
		_puts(ev[i]), _putchar('\n');
}
