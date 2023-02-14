#include <stdio.h>

int main(int ac __attribute__((unused)), char **av)
{
	int i;
	
	for (i = 0; av[i]; i++)
		printf("%s\n", av[i]);
	return (0);
}
