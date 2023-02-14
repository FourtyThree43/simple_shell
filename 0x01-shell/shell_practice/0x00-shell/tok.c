#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFSIZE 1024

/**
 * tokenize - tokenize a string
 *
 * Return: array of tokens.
 */
char **tokenize()
{
	char str[BUFFSIZE];
	char *token;
	char *s = " ";
	char **ret;
	int i = 0, j;

	fgets(str, BUFFSIZE, stdin);
	token = strtok(str, s);

	ret = malloc(sizeof(char *));
	if (!ret)
	{
		dprintf(2, "Error: malloc() failure\n");
		exit(EXIT_FAILURE);
	}
	while (token)
	{
		ret[i] = malloc(strlen(token) + 1);
		if (!(ret[i]))
		{
			dprintf(2, "Error: malloc() failure\n");
			exit(EXIT_FAILURE);
		}
		for (j = 0; token[j]; j++)
			(ret[i])[j] = token[j];
		token = strtok(NULL, s);
		i++;
		/*increase the size of the array*/
		ret = realloc(ret, (i + 1) * sizeof(char *));
		if (!ret)
		{
			dprintf(2, "Error: realloc() failure\n");
			exit(EXIT_FAILURE);
		}
	}

	ret[i] = NULL;
	return (ret);
}

/**
 * main - entry point
 *
 * Return: EXIT_SUCCESS.
*/
int main(void)
{
	char **arr = tokenize();
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
