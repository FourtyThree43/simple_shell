/**
 * _getenv - function that gets an environment variable.
 * @name: name of the environment variable.
 *
 * Return: pointer to the value of the environment variable,
 *         or NULL if not found.
 */
char *_getenv(const char *name)
{
	char *value = NULL;
	int i, len;

	if (name == NULL)
		return (NULL);

	len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			value = environ[i] + len + 1;
			break;
		}
	}

	return (value);
}
