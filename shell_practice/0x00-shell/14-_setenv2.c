#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _setenv - set an environment variable
 * @name: the name of the environment variable
 * @value: the value to set the environment variable to
 * @overwrite: whether to overwrite an existing environment variable with the same name
 *
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		return -1;
	}

	// Check if the environment variable already exists
	int i = 0;
	while (environ[i] != NULL)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			if (overwrite)
			{
				// Overwrite the existing variable
				size_t new_env_len = strlen(name) + 1 + strlen(value) + 1;
				char *new_env = malloc(new_env_len);
				if (new_env == NULL)
				{
					return -1;
				}
				strcpy(new_env, name);
				strcat(new_env, "=");
				strcat(new_env, value);
				free(environ[i]);
				environ[i] = new_env;
			}
			return 0;
		}
		i++;
	}

	// Add a new environment variable
	size_t new_env_len = strlen(name) + 1 + strlen(value) + 1;
	char *new_env = malloc(new_env_len);
	if (new_env == NULL)
	{
		return -1;
	}
	strcpy(new_env, name);
	strcat(new_env, "=");
	strcat(new_env, value);

	// Allocate a new environ array with space for the new variable
	int environ_size = i;
	char **new_environ = malloc(sizeof(char *) * (environ_size + 2));
	if (new_environ == NULL)
	{
		free(new_env);
		return -1;
	}

	// Copy the existing environ array into the new array
	for (int j = 0; j < environ_size; j++)
	{
		new_environ[j] = environ[j];
	}

	// Add the new variable to the new array
	new_environ[environ_size] = new_env;
	new_environ[environ_size + 1] = NULL;

	// Set the global environ variable to the new array
/*	for (i = 0; environ[i]; i++)
		free(environ[i]);
	free(environ);
*/	environ = new_environ;

	return 0;
}

// C program to illustrate setenv function
int main()
{
	char *pth;
	int i;
	if(_setenv("INCLUDE","usr/nto//include:/home/scholar/include",1)==0)
		{
			if((pth=getenv("INCLUDE"))!=NULL)
				printf("\n\n\tINCLUDE:%s\n\n\t",pth);
			free(pth - 8);
		}
	else
	{
			printf("\n\n\tError! No such Environment Value Exists.");
	}

/*	for (i = 0; environ[i]; i++)
		free(environ[i]);
*/	free(environ);
	return 0;
}
