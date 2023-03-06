#include "../shell.h"

int main(void)
{
	char *input_str;

	while (1)
	{
		input_str = get_line();
		if (input_str == NULL)
		{
			perror("my_getline");
			exit(EXIT_FAILURE);
		}

		if (strcmp(input_str, "exit") == 0)
			break;

		printf("You entered: %s\n", input_str);
		free(input_str);
	}

	printf("Goodbye!\n");
	return (0);
}
