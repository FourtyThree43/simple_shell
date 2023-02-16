#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - print nos. 1 - 5 and 6 - 10 in child and parent processes
 * respectively
 *
 * Return: 0.
 */
int main(void)
{
	int pid = fork();
	int n;

	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
		wait(NULL);
	}

	for (int i = n; i < n + 5; i++)
	{
		printf(" %d", i);
		if (i == 10)
			putchar(10);
		fflush(stdout);
	}

	return (0);
}
