#include "../shell.h"
#include <stdio.h>

int main(void)
{
	printf("Testing execute function...\n");
	char *input = get_input();
	// char *input = "ls -l /usr/bin";
	char **args = tokenize_input(input);

	//char *args[] = {"a", NULL, NULL};
	execute(args);
	
	// args[0] = "echo";
	// args[1] = "hello, world!";
	// args[2] = NULL;
	// execute(args);
	
	free(input);
	free_tokens(args);
	return (0);
}
