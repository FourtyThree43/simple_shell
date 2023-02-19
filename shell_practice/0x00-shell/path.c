#include "main.h"
#include "tok.c"
#include "_getenv.c"

/**
 * print_path - prints each directory contained in $PATH
 *
 * Return: EXIT_SUCCESS.
 */
 void print_path(void)
 {
	 char *path = _getenv("PATH");
	 char *str = path + 5;
	 char **dir = tokenize(str, ":");
	 unsigned int i;
	
	if (!(path))
		dprintf(2, "$PATH not found!\n"), exit(EXIT_FAILURE);
	for (i = 0; dir[i]; i++)
	{
		puts(dir[i]);
		free(dir[i]);
	}
	free(dir);
 }
 
 int main(void)
 {
	print_path();
	exit(EXIT_SUCCESS);
 }