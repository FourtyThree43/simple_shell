#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFSIZE 1024

/**
 * tokenize - tokeize a string
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
/*
*	char nl = '\n';
*	int wrt;
*/
	for (i = 0; arr[i]; i++)
	{
		if (arr[i + 1] == NULL)
		{
			printf("%s", arr[i]);
		}
		else
			puts(arr[i]);
/*
*		if (arr[i + 1] == NULL)
*		{
*			wrt = write(STDOUT_FILENO, arr[i], strlen(arr[i]));
*			if (wrt == -1)
*			{
*				dprintf(STDERR_FILENO, "Error: write() failure\n");
*				exit(EXIT_FAILURE);
*			}
*		}
*		else
*		{
*			wrt = write(STDOUT_FILENO, arr[i], strlen(arr[i]));
*			if (wrt == -1)
*			{
*				dprintf(STDERR_FILENO, "Error: write() failure\n");
*				exit(EXIT_FAILURE);
*			}
*			wrt = write(STDOUT_FILENO, &nl, 1);
*			if (wrt == -1)
*			{
*				dprintf(STDERR_FILENO, "Error: write() failure\n");
*				exit(EXIT_FAILURE);
*			}
*		}
*/	}
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	exit(EXIT_SUCCESS);
}
