#include "shell.h"

/**
 * which - stat a filename
 * @filename: pointer to `filename` string
 * @path: pointer to path value string
 * Return: pointer to full path (success), or NULL (failure).
*/
char *which(char *filename, const char *path)
{
	struct stat st;
	int stat_ret, i;
	char buf[MAXLEN], tempath[MAXLEN], **temp, *ret;

	memset(buf, 0, MAXLEN), memset(tempath, 0, MAXLEN);
	strcpy(tempath, path);
	temp = tokenize(tempath, ":");
	if (filename[0] != '/')
	{
		for (i = 0; temp[i]; i++)
		{
			memset(buf, 0, MAXLEN), strcpy(buf, temp[i]), strcat(buf, "/");
			strcat(buf, filename);
			stat_ret = stat(buf, &st);
			if (stat_ret == 0)
			{
				free_tok(temp);
				ret = strdup(buf);
				return (ret);
			}
		}
	}
	else
	{
		if (!(stat(filename, &st)))
		{
			for (i = 0; temp[i]; i++)
			{
				if (!(strncmp(temp[i], filename, strlen(temp[i]))))
				{
					free_tok(temp);
					ret = strdup(filename);
					return (ret);
				}
			}
		}
	}
	free_tok(temp);
	return (NULL);
}
