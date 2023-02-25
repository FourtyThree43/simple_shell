#include "shell.h"

/**
 * which - stat a filename
 * @filename: pointer to `filename` string
 *
 * Return: pointer to full path (success), or NULL (failure).
*/
char *which(char *filename)
{
	struct stat st;
	int stat_ret, i;
	char buf[MAXLEN], *temp, *ret, **path;

	temp = _getenv("PATH");
	if (!temp)
		return (NULL);
	path = tokenize(temp, ":");
	if (!path)
		return (NULL);
	for (i = 0; path[i]; i++)
	{
		_memset(buf, 0, MAXLEN);
		_strcpy(buf, path[i]);
		_strcat(buf, "/");
		_strcat(buf, filename);
		stat_ret = stat(buf, &st);
		if (stat_ret == 0)
		{
			free_tok(path);
			ret = &(buf[0]);
			return (ret);
		}
	}
	if (stat_ret == -1)
		free_tok(path);
	return (NULL);
}
