#define _GNU_SOURCE
#define BUFFSIZE 1024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int ac, char **av)
{
	char *cwd, pathname[BUFFSIZE];
	struct stat st;
	int i = 1, error = 0, idx, tmp, j, abscheck = 0;

	memset(pathname, 0, 1024);

	if (ac < 2)
	{
		dprintf(2, "Usage: %s <filename> ...\n", av[0]);
		return (1);
	}

	cwd = get_current_dir_name();

	for (idx = 0; cwd[idx]; idx++)
		pathname[idx] = cwd[idx];
	pathname[idx++] = '/';

	while (av[i])
	{
		tmp = idx;
		for (j = 0; (av[i])[j]; tmp++, j++)
		{
			if ((strncmp(av[i], pathname, (unsigned int)idx)) == 0)
			{
				abscheck = 1;
				break;
			}
			pathname[tmp] = (av[i])[j];
		}
		if(stat(av[i], &st) == 0)
		{
			if (abscheck == 0)
				puts(pathname);
			else
				puts(av[i]);
		}
		else
			error = 1;

		i++;
	}

	if (error == 1)
		dprintf(2, " ");

	free(cwd);
	return (error);
}
