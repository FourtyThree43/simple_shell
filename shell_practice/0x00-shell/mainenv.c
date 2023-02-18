#include <stdio.h>

/*
 * main - print the current environment
 * @ac: arg count
 * @av: arg vector
 * @env: pointer to environment
 *
 * Return: 0.
 */
int main(int ac __attribute__ ((unused)), char **av __attribute__ ((unused)), \
char **env)
{
	unsigned int i;

	for (i = 0; env[i]; i++)
		puts(env[i]);
	return (0);
}
