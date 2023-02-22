#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string1.c"

/*
 * main - print the current environment
 *
 * Return: 0.
 */
int main(void)
{
	unsigned int i;
	
	for (i = 0; environ[i]; i++)
		_puts(environ[i]), _putchar('\n');
	return (0);
}
