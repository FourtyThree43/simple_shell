#include "../shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 *_putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _sprintf - implementation of sprintf
 * @str: string
 * @format: format specifier
 *
 * Return: number of characters printed.
*/
int _sprintf(char *str, const char *format, ...)
{
	va_list args;
	int i = 0;

	va_start(args, format);
	while (*format)
	{
		/* If the format specifier is encountered*/
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				{
					int arg = va_arg(args, int);
					int j = 0, k = arg;

					/* Reverse the number*/
					while (k)
					{
						str[i++] = (k % 10) + '0';
						k /= 10;
						j++;
					}

					/* Reverse the string*/
					for (j = j - 1; j >= 0; j--, i++)
						str[i] = str[i - j - 1];
					break;
				}

				case 's':
				{
					char *arg = va_arg(args, char *);
					int j = 0;

					/* Copy the string*/
					while (arg[j] != '\0')
						str[i++] = arg[j++];
					break;
				}
			}
		}
		else
			str[i++] = *format;

		format++;
	}
	va_end(args);

	/* Add null terminator */
	str[i] = '\0';

	return (i);
}
