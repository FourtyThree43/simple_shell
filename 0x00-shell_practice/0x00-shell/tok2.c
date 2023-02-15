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

	fgets(str, BUFFSIZE, stdin); // read input from stdin

	token = strtok(str, s); // get the first token

	/* allocate memory for the array of tokens */
	ret = malloc(sizeof(char *));
	if (!ret)
	{
		dprintf(2, "Error: malloc() failure\n");
		exit(EXIT_FAILURE);
	}

	while (token)
	{
		ret[i] = malloc(strlen(token) + 1); // allocate memory for each token
		if (!ret[i])
		{
			dprintf(2, "Error: malloc() failure\n");
			exit(EXIT_FAILURE);
		}
		for (j = 0; token[j]; j++)
			ret[i][j] = token[j]; // copy the characters of the token into the array
		token = strtok(NULL, s); // get the next token
		i++;
		ret = realloc(ret, (i + 1) * sizeof(char *)); // increase the size of the array
		if (!ret)
		{
			dprintf(2, "Error: realloc() failure\n");
			exit(EXIT_FAILURE);
		}
	}

	ret[i] = NULL; // set the last element to NULL to mark the end of the array

	return ret;
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
			printf("%s", arr[i]); // print the last element without a newline
		else
			puts(arr[i]); // print the element with a newline
	}

	/* free the memory allocated for each token and for the array */
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);

	exit(EXIT_SUCCESS);
}
