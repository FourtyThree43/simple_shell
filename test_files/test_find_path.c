#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *path = get_path();
	printf("PATH = %s\n", path);
	
	char *cmd = "ls";
	char *fullpath = find_in_path(cmd);
	printf("Full path for %s: %s\n", cmd, fullpath);
	
	return (0);
}
