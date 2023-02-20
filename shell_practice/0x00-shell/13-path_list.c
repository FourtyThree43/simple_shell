#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A structure to represent a node in the linked list of directories.
 */
typedef struct DirectoryNode
{
  char *directory;
  struct DirectoryNode *next;
} DirectoryNode;

/**
 * build_path_list - builds a linked list of directories in the PATH environment variable
 *
 * Return: a pointer to the head of the linked list, or NULL if an error occurred
 */
DirectoryNode *build_path_list()
{
  char *path = getenv("PATH");
  if (path == NULL)
  {
    printf("PATH environment variable not found\n");
    return NULL;
  }

  char *path_copy = strdup(path);
  if (path_copy == NULL)
  {
    printf("Error: out of memory\n");
    return NULL;
  }

  DirectoryNode *head = NULL;
  DirectoryNode *tail = NULL;

  char *dir = strtok(path_copy, ":");
  while (dir != NULL)
  {
    DirectoryNode *node = (DirectoryNode *)malloc(sizeof(DirectoryNode));
    if (node == NULL)
    {
      printf("Error: out of memory\n");
      free(path_copy);
      return NULL;
    }

    node->directory = strdup(dir);
    if (node->directory == NULL)
    {
      printf("Error: out of memory\n");
      free(node);
      free(path_copy);
      return NULL;
    }

    node->next = NULL;

    if (head == NULL)
    {
      head = node;
      tail = node;
    }
    else
    {
      tail->next = node;
      tail = node;
    }

    dir = strtok(NULL, ":");
  }

  free(path_copy);

  return head;
}

/**
 * free_path_list - frees the memory allocated for the linked list of directories
 * @head: the head of the linked list
 */
void free_path_list(DirectoryNode *head)
{
  DirectoryNode *current = head;
  while (current != NULL)
  {
    DirectoryNode *next = current->next;
    free(current->directory);
    free(current);
    current = next;
  }
}

/**
 * print_path_list - prints the linked list of directories to standard output
 * @head: the head of the linked list
 */
void print_path_list(DirectoryNode *head)
{
  for (DirectoryNode *current = head; current != NULL; current = current->next)
  {
    printf("%s\n", current->directory);
  }
}

/**
 * main - entry point for the program
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 on success, non-zero on error
 */
int main(int argc, char **argv)
{
  DirectoryNode *head = build_path_list();
  if (head == NULL)
  {
    return EXIT_FAILURE;
  }

  print_path_list(head);

  free_path_list(head);

  return EXIT_SUCCESS;
}
