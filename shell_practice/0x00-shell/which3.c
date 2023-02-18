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
	int abs_path;

	memset(pathname, 0, 1024);

	if (ac < 2)
	{
		dprintf(2, "Usage: %s <filename> ...\n", av[0]);
		return (1);
	}

/*	str = "/home/kemboiray/ALX-Local/simple_shell/shell_practice/0x00-shell/";
	for (idx = 0; str[idx]; idx++)
		pathname[idx] = str[idx];
*/
	str = getcwd(NULL, 0);
	if (str == NULL)
	{
		perror("getcwd error");
		return (1);
	}

	idx = strlen(str);
	for (j = 0; j < idx; j++)
		pathname[j] = str[j];
	pathname[idx++] = '/';

	while (av[i])
	{
		tmp = idx;
		for (j = 0; (av[i])[j]; tmp++, j++)
			pathname[tmp] = (av[i])[j];

		if (av[i][0] == '/')
		{
			abs_path = 1;
			puts("used abs");
		}
		else
		{	
			abs_path = 0;
			puts("not abs");
		}

		if (stat(av[i], &st) == 0)
			puts(pathname);
		else
			error = 1;

		i++;
	}

	if (error == 1)
		dprintf(2, " ");

	free(str);
	return (error);
}
