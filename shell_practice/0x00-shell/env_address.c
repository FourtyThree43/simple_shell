#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

/*
 * main - print the addresses of env and environ respectively
 * @ac: arg count
 * @av: arg vector
 * @env: pointer to environment
 *
 * Return: 0.
 */
int main(int ac __attribute__ ((unused)), char **av __attribute__ ((unused)), char **env)
{
	printf("&env: %p\n", &env);
	printf("&environ: %p\n", &environ);
	return (0);
}
