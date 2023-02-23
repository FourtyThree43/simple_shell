#include "main.h"
#define BUFFSIZE 4096

/**
 * main - locates a command
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 (success), 1 (failure).
 */
int main(int ac, char **av)
{
	struct stat st;
	int stat_ret, i, j, extat = 0;
	char buf[BUFFSIZE], *temp, **tempath, **path;

	if (ac < 2)
		dprintf(2, "Usage: %s <filename> ...\n", av[0]), exit(1);
	temp = _getenv("PATH");
	if (!temp)
		dprintf(2, "PATH not found!\n"), exit(1);
	path = tokenize(temp, ":");
	if (!path)
		dprintf(2, "Memory allocation error!\n"), exit(1);

	for (i = 1; av[i]; i++)
	{
		if (av[i][0] == '/')
		{
			if (stat(av[i], &st) == -1)
			{
				extat = 1;
				continue;
			}
			tempath = tokenize(av[i], "/");
			if (!tempath)
			{
				cleaner(path);
				dprintf(2, "Memory allocation error!\n"), exit(1);
			}
			for (j = 0; tempath[j]; j++)
				;
			for(j = 0; path[j]; j++)
			{
				memset(buf, 0, BUFFSIZE);
				strcpy(buf, path[j]);
				strcat(buf, "/");
				strcat(buf, tempath[j - 1]);
				stat_ret = stat(buf, &st);
				if (stat_ret == 0)
				{
					puts(buf);
					break;
				}
			}
			if (stat_ret == -1)
				extat = 1;
			cleaner(tempath);
		}
		else
		{
			for (j = 0; path[j]; j++)
			{
				memset(buf, 0, BUFFSIZE);
				strcpy(buf, path[j]);
				strcat(buf, "/");
				strcat(buf, av[i]);
				stat_ret = stat(buf, &st);
				if (stat_ret == 0)
				{
					puts(buf);
					break;
				}
			}
			if (stat_ret == -1)
				extat = 1;
		}
	}
	cleaner(path);
	exit(extat);
}
