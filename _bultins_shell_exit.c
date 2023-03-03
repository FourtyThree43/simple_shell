#include "shell.h"

/**
 * shell_exit - Exit the shell.
 * @status: Exit Status.
 *
 * Return: Nothing.
 */
void shell_exit(int status)
{
	_puts("exit\n");
	exit(status);
}
