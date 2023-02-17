#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int ac, char **av)
{
	char *str, pathname[1024];
	struct stat st;
	int i = 1, error = 0, idx, tmp, j;
	
	memset(pathname, 0, 1024);
	
	if (ac < 2)
	{
		dprintf(2, "Usage: %s <filename> ...\n", av[0]);
		return (1);
	}
	
	str = "/home/kemboiray/ALX-Local/simple_shell/shell_practice/0x00-shell/";
	for (idx = 0; str[idx]; idx++)
		pathname[idx] = str[idx];
	
	while (av[i])
	{
		tmp = idx;
		for (j = 0; (av[i])[j]; tmp++, j++)
			pathname[tmp] = (av[i])[j];
		if(stat(av[i], &st) == 0)
			puts(pathname);
		else
			error = 1;
		i++;
	}
	if (error == 1)
		dprintf(2, " ");
	return (error);
}
