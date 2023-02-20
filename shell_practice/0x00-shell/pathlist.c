#include "main.h"
#include "tok.c"
#include "_getenv.c"

/**
 * path_ptrs - returns an array of directories in $PATH
 *
 * Return: see description.
 */
char **path_ptrs(void)
{
	char *path = _getenv("PATH");
	char *str = path;
	char **dir = tokenize(str, ":");
	unsigned int i;
	
	if (!(path))
		dprintf(2, "$PATH not found!\n"), exit(EXIT_FAILURE);

	return (dir);
}
 
/** build_list - builds a linked list of directories in $PATH.
 *
 * Return: pointer to beginning of list.
 */
path_list *build_list(void)
{
	int i;
	char **ptrs = path_ptrs();
	path_list *head;
	path_list *temp = NULL;
	
	/* Whiteboarding */
	if (!(head = malloc(sizeof(path_list))))
		dprintf(2, "malloc() failure\n"), exit(EXIT_FAILURE);
	head->dir_node = ptrs[0];
	head->next = NULL;
	temp = head;
	for (i = 1; ptrs[i]; i++)
	{
		if (!(temp->next = malloc(sizeof(path_list))))
			dprintf(2, "malloc() failure\n"), exit(EXIT_FAILURE);
		temp = temp->next;
		temp->dir_node = ptrs[i];
		temp->next = NULL;
	}
	return (head);
}
 
/**
 * free_list - frees a singly-linked list
 * @head: pointer to first node
 *
 * Return: void.
 */
void free_list(path_list *head)
{
	path_list *temp;
//	char **ptr;
	int i;

#if 0	
	for (temp = head; temp->dir_node; temp = temp->next)
		if((temp->dir_node))
			free(temp->dir_node);
	if (&(head->dir_node))
		free(&(head->dir_node));
#endif
//	ptr = &(head->dir_node);
	while (head)
	{
		temp = head->next;
		free(head->dir_node);
		free(head);
		head = temp;
	}
//	free(ptr);
}
/**
 * main - print linked list
 *
 * Return: 0.
 */
int main(void)
{
	path_list *head = build_list();
	path_list *temp = head;
	while(temp)
	{
		puts(temp->dir_node);
		temp = temp->next;
	}
	free_list(head);
	return 0;
}
 