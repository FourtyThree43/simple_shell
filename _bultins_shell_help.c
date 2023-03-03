#include "shell.h"

/**
 * shell_help - displays help information for built-in commands
 */
void shell_help(void)
{
	_puts("Shell Version 1.0.0");
	_puts("Usage: ./hsh\n");
	_puts("Shell built-in commands:");
	_puts("help\t\tDisplay this help information\n");
	_puts("cd [dir]\tChange the current working directory\n");
	_puts("printenv\tDisplay the environment variables\n");
	_puts("setenv\t\tSet an environment variable\n");
	_puts("unsetenv\tUnset an environment variable\n");
	_puts("exit\t\tExit the shell\n");
}
