#include "shell.h"

/**
 * _getenv - return the value corresponding to an environment variable name
 * @name: variable name
 *
 * Return: value string (success), or NULL (failure).
 */
char *_getenv(const char *name)
{
	unsigned int i, idx;
	char *buf;

	idx = strlen(name);
	buf = calloc(idx + 2, sizeof(char));
	if (!(buf))
		dprintf(STDERR_FILENO, "calloc() failure\n"), exit(-1);

	for (i = 0; environ[i]; i++)
	{
		if (!(strcpy(buf, name)))
		{
			free(buf);
			dprintf(STDERR_FILENO, "strcpy() failure\n"), exit(-1);
		}
		buf[idx] = '=';
		if (strncmp(buf, environ[i], strlen(buf)) == 0)
		{
			free(buf);
			return (environ[i] + idx + 1);
		}
	}
	free(buf);
	return (NULL);
}
