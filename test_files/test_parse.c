#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *input = "ls -l /usr/bin";
	char **tokens = tokenize_input(input);

	_puts("Testing prompt function...\n");
	for (int i = 0; tokens[i] != NULL; i++)
	{
		printf("Token %d: %s\n", i, tokens[i]);
	}

	free_tokens(tokens);

	return (0);
}
