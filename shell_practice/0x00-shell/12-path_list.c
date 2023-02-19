#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct dir_node - A directory node in a linked list of directories
 *
 * @path: A pointer to a string representing a directory path
 * @next: A pointer to the next dir_node in the linked list
 */
typedef struct dir_node
{
    char *path;
    struct dir_node *next;
} dir_node;

/**
 * build_path_list - Builds a linked list of directories in the PATH variable
 *
 * Return: A pointer to the head of the linked list
 */
dir_node *build_path_list(void)
{
    /* Get the PATH environment variable */
    char *path_str = getenv("PATH");

    /* Allocate memory for the head of the linked list */
    dir_node *head = malloc(sizeof(dir_node));
    dir_node *cur;
    dir_node *new_node;
    char *path_token;
    size_t path_len;

    /* Check for errors */
    if (path_str == NULL)
    {
        fprintf(stderr, "Error: PATH environment variable not found\n");
        exit(EXIT_FAILURE);
    }

    if (head == NULL)
    {
        fprintf(stderr, "Error: malloc() failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the head node of the linked list */
    head->path = NULL;
    head->next = NULL;
    cur = head;

    /* Tokenize the PATH string and create a linked list of directories */
    path_token = strtok(path_str, ":");
    while (path_token != NULL)
    {
        /* Allocate memory for a new node in the linked list */
        new_node = malloc(sizeof(dir_node));
        if (new_node == NULL)
        {
            fprintf(stderr, "Error: malloc() failed\n");
            exit(EXIT_FAILURE);
        }

        /* Allocate memory for the path string in the new node */
        path_len = strlen(path_token);
        new_node->path = malloc(path_len + 1);
        if (new_node->path == NULL)
        {
            fprintf(stderr, "Error: malloc() failed\n");
            exit(EXIT_FAILURE);
        }

        /* Copy the path string to the new node */
        strcpy(new_node->path, path_token);

        /* Set the next pointer of the current node to the new node */
        new_node->next = NULL;
        cur->next = new_node;

        /* Update the current node to be the new node */
        cur = new_node;

        /* Get the next token from the PATH string */
        path_token = strtok(NULL, ":");
    }

    /* Return a pointer to the head of the linked list */
    return head;
}
