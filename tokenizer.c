#include "shell.h"

/**
 * tokenize - tokenize a string
 * @str: string
 * @delim: delimiter
 *
 * Return: array of tokens.
 */
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **ret = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (i + 1));
		if (ret == NULL)
			return (NULL);

		ret[i] = malloc(strlen(token) + 1);
		if (!(ret[i]))
			return (NULL);

		strcpy(ret[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increase the size of the array*/
	ret = realloc(ret, (i + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	ret[i] = NULL;
	return (ret);
}
