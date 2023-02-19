#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Struct definition for a directory node in the linked list.
 */
typedef struct dir_node {
    char *path;
    struct dir_node *next;
} dir_node;

/**
 * Builds a linked list of the directories in the PATH environment variable.
 *
 * Returns a pointer to the head of the linked list.
 */
dir_node *build_path_list(void) {
    // Get the PATH environment variable
    char *path_str = getenv("PATH");
    if (path_str == NULL) {
        fprintf(stderr, "Error: PATH environment variable not found\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the head of the linked list
    dir_node *head = malloc(sizeof(dir_node));
    if (head == NULL) {
        fprintf(stderr, "Error: malloc() failed\n");
        exit(EXIT_FAILURE);
    }
    head->path = NULL;
    head->next = NULL;

    // Tokenize the PATH string
    char *path_token = strtok(path_str, ":");
    dir_node *cur = head;
    while (path_token != NULL) {
        // Allocate memory for a new directory node
        dir_node *new_node = malloc(sizeof(dir_node));
        if (new_node == NULL) {
            fprintf(stderr, "Error: malloc() failed\n");
            exit(EXIT_FAILURE);
        }

        // Copy the path string to the new node
        size_t path_len = strlen(path_token);
        new_node->path = malloc(path_len + 1);
        if (new_node->path == NULL) {
            fprintf(stderr, "Error: malloc() failed\n");
            exit(EXIT_FAILURE);
        }
        strcpy(new_node->path, path_token);
        new_node->next = NULL;

        // Append the new node to the linked list
        cur->next = new_node;
        cur = new_node;

        // Get the next token from the PATH string
        path_token = strtok(NULL, ":");
    }

    return head;
}
