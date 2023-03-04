#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *dir = _getenv("PWD");
	printf("Current directory: %s\n", dir);

	char *args[] = {"cd", "..", NULL};
	shell_cd(args);

	char *args3[] = {"cd", "_test_", NULL};
	shell_cd(args3);

	dir = _getenv("PWD");
	printf("Current directory: %s\n", dir);

	args[0] = "setenv";
	args[1] = "SHELL";
	args[2] = "myshell";
	args[3] = NULL;
	shell_setenv(args);

	/* Get the value of the environment variable */
	char *value = getenv("SHELL");
	if (value == NULL)
	{
		fprintf(stderr, "Failed to get environment variable\n");
		exit(EXIT_FAILURE);
	}
	if (strcmp(value, "myshell") != 0)
	{
		fprintf(stderr, "Unexpected environment variable value: %s\n", value);
		exit(EXIT_FAILURE);
	}

	args[0] = "unsetenv";
	args[1] = "SHELL";
	args[2] = NULL;
	shell_unsetenv(args);

	/* Get the value of the environment variable again */
	value = getenv("MYVAR");
	if (value != NULL)
	{
		fprintf(stderr, "Environment variable was not unset\n");
		exit(EXIT_FAILURE);
	}

	printf("All setenv and unsetenv tests passed\n");

	args[0] = "exit";
	args[1] = NULL;
	shell_exit(args);

	return (0);
}
