#include "shell.h"

/**
 * shell_exit - exits the shell
 * @args: arguments passed to the function
 *
 * Return: 0 on success, -1 on failure
 */
int shell_exit(char **args)
{
	int status = 0;

	if (args && args[1])
	{
		status = atoi(args[1]);
		if (status == 0 && strcmp(args[1], "0") != 0)
		{
			_puterror("Illegal number: ");
			_puterror(args[1]);
			_puterror("\n");
			return (-1);
		}
	}

	free(args);
	exit(status);
}

/**
 * shell_cd - changes the current directory
 * @args: arguments passed to the function
 *
 * Return: 0 on success, -1 on failure
 */
int shell_cd(char **args)
{
	char *home = getenv("HOME");
	char *path = args[1];

	if (!path)
	{
		if (home)
			path = home;
		else
			return (-1);
	}

	if (chdir(path) == -1)
	{
		_puterror("cd: can't cd to ");
		_puterror(path);
		_puterror("\n");
		return (-1);
	}

	return (0);
}

/**
 * shell_env - prints the current environment
 * @args: arguments passed to the function
 *
 * Return: 0 on success, -1 on failure
 */
int shell_env(char **args)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		_puts(environ[i]);

	return (0);
}
