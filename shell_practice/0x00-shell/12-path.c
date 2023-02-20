#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_path - prints each directory in the PATH environment variable
 */
void print_path()
{
  char *path = getenv("PATH");
  if (path == NULL)
  {
    printf("PATH environment variable not found\n");
    return;
  }

  char *path_copy = strdup(path);
  if (path_copy == NULL)
  {
    printf("Error: out of memory\n");
    return;
  }

  char *dir = strtok(path_copy, ":");
  while (dir != NULL)
  {
    printf("%s\n", dir);
    dir = strtok(NULL, ":");
  }

  free(path_copy);
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
  print_path();
  return EXIT_SUCCESS;
}
