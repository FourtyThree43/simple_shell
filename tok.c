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

		ret[i] = malloc(_strlen(token) + 1);
		if (!(ret[i]))
			return (NULL);

		_strcpy(ret[i], token);
		token = strtok(NULL, delim);
		i++;
		/*increase the size of the array*/
		ret = realloc(ret, (i + 1) * sizeof(char *));
		if (!ret)
			return (NULL);
	}

	ret[i] = NULL;
	return (ret);
}
#if 0
/**
 * main - entry point
 *
 * Return: EXIT_SUCCESS.
*/
int main(void)
{
	char str[] = "raymond:kemboi\n";
	char **arr = tokenize(str, ":");
	int i;

	for (i = 0; arr[i]; i++)
	{
		if (arr[i + 1] == NULL)
		{
			printf("%s", arr[i]);
		}
		else
			puts(arr[i]);
	}
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);

	exit(EXIT_SUCCESS);
}
#endif
