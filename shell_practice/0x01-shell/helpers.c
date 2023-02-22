#include "shell.h"

/**
 * _putchar - write character to stdout
 * @c: character to print
 *
 * Return: On success 1, on error, -1 is returned,
 *         and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puterror - writes an error message to standard error
 * @str: the error message to write
 */
void _puterror(char *str)
{
		int len;

		len = _strlen(str);
		write(STDERR_FILENO, str, len);
}

/**
 * _strlen - calculate the length of a string
 * @s: string to calculate length of
 *
 * Return: length of string
 */
size_t _strlen(char *s)
{
	size_t len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strdup - duplicate a string
 * @s: string to duplicate
 *
 * Return: pointer to new string, or NULL if allocation fails
 */
char *_strdup(char *s)
{
	char *dup;
	size_t len;

	if (!s)
		return (NULL);

	len = _strlen(s);

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	for (size_t i = 0; i <= len; i++)
		dup[i] = s[i];

	return (dup);
}

/**
 * _strcmp - compare two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 0 if strings are equal, non-zero otherwise
 */
int _strcmp(char *s1, char *s2)
{
	size_t i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);

	return (0);
}
