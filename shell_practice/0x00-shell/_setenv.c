#include "main.h"
#include "pathlist.c"
#include "_getenvfull.c"

/**
 * _setenv - custom implementation of setenv()
 * @name: variable name
 * @value: string value with which `name` may be set
 * @overwrite: integer value indicating whether an existing value string
 * should be overwritten
 *
 * Return: 0 (success), or -1 (failure).
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *ptr = _getenvfull(name);
	path_list *head = build_list(environ);
	path_list *temp = head;

	if (ptr)
	{
		if (overwrite == 0)
			return (0);
		else
		{
			while(1)
			{
				if (!(strcmp(ptr, temp->dir_node)))
				{
					temp->dir_node = calloc(strlen(value) + 1, sizeof(char));
					if (!(temp->dir_node))
					{
						dprintf(2, "calloc() failure\n");
						return (-1);
					}
					temp->dir_node = (char *)value;
					break;
				}
				temp = temp->next;
			}
		}
	}
	else
	{
		while(temp)
			temp = temp->next;
		temp = malloc(sizeof(path_list));
		if (!(temp))
		{
			dprintf(2, "malloc() failure\n");
			return (-1);
		}
		temp->dir_node = (char *)value;
		temp->next = NULL;
	}
	return (0);
}

/**
 * main - check code
 *
 * Return: 0.
 */
int main(void)
{	
	printf("Before: %s\n", _getenvfull("USER"));
	_setenv("USER", "raymond", 1);
	printf("After: %s\n", _getenvfull("USER"));
	_setenv("AAHAV", "meaningless", 1);
//	printf("%s\n", _getenvfull("AAHAV"));
	return (0);
}
