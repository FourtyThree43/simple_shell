#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - retrieves the value of an environment variable by its name
 * @name: the name of the environment variable to retrieve
 *
 * Return: a pointer to the value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
  extern char **environ;
  size_t namelen = strlen(name);

  for (char **env = environ; *env != NULL; env++)
  {
	if (strncmp(name, *env, namelen) == 0 && (*env)[namelen] == '=')
	{
	  return &((*env)[namelen + 1]);
	}
  }

  return (NULL);
}

/**
 * main - entry point for the program
 * @ac: the number of command-line arguments
 * @av: an array of strings containing the command-line arguments
 *
 * Return: 0 on success, non-zero on error
 */
int main(int ac, char **av)
{
  if (ac < 2)
  {
	fprintf(stderr, "Usage: %s <env_var_name>\n", av[0]);
	return (EXIT_FAILURE);
  }

  char *value = _getenv(av[1]);

  if (value == NULL)
  {
	printf("Environment variable '%s' not found\n", av[1]);
	return (EXIT_FAILURE);
  }

  printf("%s=%s\n", av[1], value);

  return (EXIT_SUCCESS);
}
