#include "shell.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to write
 *
 * Return: On success 1, on error -1 and errno set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - writes a string to stdout
 * @str: string to write
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _puterror - writes an error message to stderr
 * @str: error message to write
 */
void _puterror(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _strlen - returns the length of a string
 * @s: string to get length of
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcpy - copies a string to a buffer
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicate string
 */
char *_strdup(char *str)
{
	char *dup;
	int len;

	len = _strlen(str);

	dup = malloc(len + 1);

	if (dup == NULL)
		return (NULL);

	_strcpy(dup, str);

	return (dup);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if the strings match, non-zero otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);

	return (s1[i] - s2[i]);
}

/**
 * _atoi - converts a string to an integer.
 * @s: string to convert.
 *
 * Return: integer value of the string,
 *         or -1 if the string is not a valid number.
 */
int _atoi(char *s)
{
	int sign = 1, i = 0, num = 0;

	if (s == NULL)
		return (-1);

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		else
			return (-1);

		i++;
	}

	return (num * sign);
}
