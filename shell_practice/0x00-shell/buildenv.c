#include "main.h"
#include "pathlist.c"

path_list *buildenv(void)
{
	path_list *head = build_list(environ);
	return (head);
}

int main(void)
{
	path_list *head = buildenv();
	path_list *temp = head;

	while(temp)
	{
		puts(temp->dir_node);
		temp = temp->next;
	}
	free_list(head, 0);
	return 0;
}
