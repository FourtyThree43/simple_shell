#include "shell.h"

/**
 * print_prompt - Print the shell prompt
 */
void print_prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
}
