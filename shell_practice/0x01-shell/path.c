#include "shell.h"

/**
 * get_path - get the value of the PATH environment variable
 * @env: the environment variables
 *
 * Return: a pointer to the PATH value, or NULL if it is not found
 */
char *get_path(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
	}

	return (NULL);
}

/**
 * free_path_list - frees a linked list of path_t nodes
 * @head: a pointer to the head of the linked list
 */
void free_path_list(path_t *head)
{
	path_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->dir);
		free(tmp);
	}
}

/**
 * path_list - creates a linked list of directories from a PATH string
 * @path: the PATH string
 *
 * Return: a pointer to the head of the linked list
 */
path_t *path_list(char *path)
{
	path_t *head = NULL, *new = NULL, *tmp = NULL;
	char *token;

	token = strtok(path, ":");
	while (token != NULL)
	{
		new = malloc(sizeof(path_t));
		if (new == NULL)
		{
			_puterror("Memory allocation error\n");
			free_path_list(head);
			return (NULL);
		}
		new->dir = _strdup(token);
		if (new->dir == NULL)
		{
			_puterror("Memory allocation error\n");
			free(new);
			free_path_list(head);
			return (NULL);
		}
		new->next = NULL;

		if (head == NULL)
			head = new;
		else
		{
			tmp = head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}

		token = strtok(NULL, ":");
	}

	return (head);
}
