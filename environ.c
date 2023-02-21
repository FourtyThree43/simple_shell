#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * main - print the current environment
 *
 * Return: 0.
 */
int main(void)
{
	unsigned int i;
	char **tempenv;

	for (i = 0; environ[i]; i++)
		;
	tempenv = malloc((sizeof(char *)) * i + 1);
	if (tempenv == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; environ[i]; i++)
	{
		tempenv[i] = environ[i];
		puts(tempenv[i]);
	}
	free(tempenv);
	return (0);
}
