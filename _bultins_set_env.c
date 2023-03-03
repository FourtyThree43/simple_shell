#include "shell.h"

/**
 * set_env - Set the value of an environment variable
 * @args: Arguments (name and value of the environment variable)
 *
 * Return: Nothing
 */
void set_env(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		_puterror("Usage: setenv VARIABLE VALUE\n");
		return;
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		_puterror("setenv");
	}
}

/**
 * unset_env - Unset an environment variable
 * @args: Arguments (name of the environment variable)
 *
 * Return: Nothing
 */
void unset_env(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		_puterror("Usage: unsetenv VARIABLE\n");
		return;
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		_puterror("unsetenv");
	}
}
