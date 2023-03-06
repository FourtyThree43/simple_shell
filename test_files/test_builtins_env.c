#include "../shell.h"

int main(void)
{
	char **args;
	char *cmd = "env";

	args = tokenize_input(cmd);
	if (args == NULL || *args == NULL)
	{
		fprintf(stderr, "Failed to tokenize input\n");
		return (EXIT_FAILURE);
	}

	if (execute(args) != 0)
	{
		fprintf(stderr, "Failed to execute command: %s\n", cmd);
		free_tokens(args);
		return (EXIT_FAILURE);
	}

	free_tokens(args);
	return (EXIT_SUCCESS);
}
