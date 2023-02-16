#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"script.sh", NULL};
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error");
	printf("You shouldn't be seeing this.\n");
	return (0);
}
