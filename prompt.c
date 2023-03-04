#include "shell.h"

/**
 * prompt - Print shell prompt to stdin stream.
 *
 * Return: void.
 */
void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}
