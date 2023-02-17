#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {NULL, NULL};
	size_t len = 0;
	ssize_t nread;
	
	if(getline(&(argv[0]), &len, stdin) != -1)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error (execve)");
			free(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("Error (getline)");
		free(argv[0]);
		exit(EXIT_FAILURE);
	}
}
