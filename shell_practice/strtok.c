/* strtok */
#include "shell.h"
#include <stdio.h>
#include <string.h>

char* my_strtok(char* str, const char* delim)
{
	static char* save_ptr;

	if (str != NULL)
		save_ptr = str;

	if (*save_ptr == '\0')
		return (NULL);


	char* token_start = save_ptr;

	while (*save_ptr != '\0' && strchr(delim, *save_ptr) == NULL)
	{
		save_ptr++;
	}

	if (*save_ptr != '\0')
	{
		*save_ptr++ = '\0';
	}
	return (token_start);
}

int main()
{
	char str[] = "The quick brown fox jumps over the lazy dog";
	char delim[] = " ";
	char *token = my_strtok(str, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = my_strtok(NULL, delim);
	}
	return (0);
}
