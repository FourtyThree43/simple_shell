#include "main.h"

char *_getenvfull(const char *name)
{
	unsigned int i, idx;
	char *buf;

	idx = strlen(name);
	buf = calloc(idx + 2, sizeof(char));
	if (!(buf))
		dprintf(2, "calloc() failure\n"), exit(-1);

	for (i = 0; environ[i]; i++)
	{
		if (!(strcpy(buf, name)))
		{
			free(buf);
			dprintf(2, "strcpy() failure\n"), exit(-1);
		}
		buf[idx] = '=';
		if (strncmp(buf, environ[i], strlen(buf)) == 0)
		{
			free(buf);
			return (environ[i]);
		}
	}
	free(buf);
	return (NULL);
}
#if 0
int main(int ac, char **av)
{
	int i = 0;
	char *val_string;

	if (ac < 2)
		dprintf(2, "Usage: %s name ...\n", av[i]), exit(-1);
	for (i = 1; av[i]; i++)
	{
		if ((val_string = _getenv(av[i])))
			puts(val_string);
		else
			dprintf(2, "%s: not found!\n", av[i]);
	}

	exit(0);
}
#endif
