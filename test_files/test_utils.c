#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *str = "Hello, world!";
	char *str2;
	printf("%s\n", str);

	printf("Length of string: %d\n", _strlen(str));

	char *copy = _strcpy(str, str2);
	printf("Copy of string: %s\n", copy);
	//free(copy);

	char *cat = _strcat(str2, " This is a test.");
	printf("Concatenated string: %s\n", cat);
	//free(cat);

	char *dup = _strdup(str2);
	printf("Duplicate of string: %s\n", dup);
	//free(dup);

	char *substring = _strstr(str2, "world");
	printf("Substring: %s\n", substring);

	return (0);
}
