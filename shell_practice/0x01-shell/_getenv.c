#include "shell.h"

/**
 * _getenv - function that gets an environment variable.
 * @name: name of the environment variable.
 *
 * Return: pointer to the value of the environment variable,
 *         or NULL if not found.
 */
char *_getenv(char *name)
{
	char *value = NULL;
	int i, len;

	if (name == NULL)
		return (NULL);

	len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			value = environ[i] + len + 1;
			break;
		}
	}

	if (value == NULL)
	{
		_puterror("getenv: environment variable not found: ");
		_puterror(name);
		_puterror("\n");
	}

	return (value);
}
