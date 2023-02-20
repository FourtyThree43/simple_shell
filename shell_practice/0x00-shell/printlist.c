#include "main.h"

/**
 * print_path_list - prints a path_list linked list
 * @head: pointer to beginning of list
 *
 * Return: void.
 */
void print_path_list(path_list *head)
{
	path_list *temp = head;

	while(temp)
    {
        puts(temp->dir_node);
        temp = temp->next;
    }
}
