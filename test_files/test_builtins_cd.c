#include "../shell.h"

int main(void)
{
	char *dir = _getenv("PWD");
	printf("Current directory: %s\n", dir);

	char *args[] = {"cd", "..", NULL};
	shell_cd(args);

	dir = _getenv("PWD");
	printf("Current directory: %s\n", dir);

	return 0;
}
