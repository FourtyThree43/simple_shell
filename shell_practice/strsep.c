/* strsep */
#include "shell.h"
#include <stdio.h>
#include <string.h>

char* my_strsep(char** str_ptr, const char* delim)
{
	if (*str_ptr == NULL)
		return (NULL);

	char* token_start = *str_ptr;

	*str_ptr = strpbrk(token_start, delim);

	if (*str_ptr != NULL)
	{
		*(*str_ptr)++ = '\0';
	}
	return (token_start);
}

int main()
{
	char str[] = "The quick brown fox jumps over the lazy dog";
	char delim[] = " ";
	char *token, *remaining_str;

	remaining_str = str;

	while ((token = my_strsep(&remaining_str, delim)) != NULL)
	{
		printf("%s\n", token);
	}
	return (0);
}
