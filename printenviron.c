#include "shell.h"

/**
 * printenviron - print the current environment
 *
 * Return: void.
 */
void printenviron(void)
{
	unsigned int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]), _putchar('\n');
}
