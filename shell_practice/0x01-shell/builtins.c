#include "shell.h"

/**
 * shell_exit - Exit the shell
 * @args: Array of arguments
 *
 * Return: Always returns 0
 */
int shell_exit(char **args)
{
	int status = 0;

	if (args[1])
		status = _atoi(args[1]);

	free(args);
	exit(status);
}

/**
 * shell_cd - Change the current working directory
 * @args: Array of arguments
 *
 * Return: Always returns 1
 */
int shell_cd(char **args)
{
	char *dir = args[1];

	if (!dir)
		dir = _getenv("HOME");

	if (chdir(dir) == -1)
	{
		_puterror("cd: can't cd to ");
		return (1);
	}

	return (1);
}

/**
 * shell_env - Print the environment
 * @args: Array of arguments
 *
 * Return: Always returns 1
 */
int shell_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);

	return (1);
}

/**
 * _env - prints the current environment
 * @env: array of environment variables
 *
 * Return: always returns 0
 */
int _env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		_puts(env[i]), _putchar('\n');

	return (0);
}
