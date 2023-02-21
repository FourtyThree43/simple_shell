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
    int i; 
    for (i = 0; environ[i] != NULL; i++) { 
        // Check if the variable is present in the environment 
        if (strstr(environ[i], name) != NULL) { 
            // If overwrite is set, then overwrite the existing value 
            if (overwrite) { 
                // Build the string in the format "name=value" 
                char *str = (char *)malloc(strlen(name) + strlen(value) + 2); 
                sprintf(str, "%s=%s", name, value); 
  
                // Replace the existing string with the new one 
                environ[i] = str; 
            } 
  
            // Variable is changed or added 
            return 0; 
        } 
    } 
  
    // Variable not found, so add it 
    environ[i] = (char *)malloc(strlen(name) + strlen(value) + 2); 
    sprintf(environ[i], "%s=%s", name, value); 
    return 0; 
}

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
	free(environ);
*/	return 0;
}
