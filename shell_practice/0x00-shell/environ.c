#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

/*
 * main - print the current environment
 *
 * Return: 0.
 */
int main(void)
{
	unsigned int i;

	for (i = 0; environ[i]; i++)
		puts(environ[i]);
	return (0);
}
