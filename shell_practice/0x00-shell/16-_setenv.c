#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern char **environ;

int _sprintf(char *str, const char *format, ...) 
{ 
    va_list args;
    int i = 0;
  
    va_start(args, format); 
    while (*format) 
    { 
        // If the format specifier is encountered 
        if (*format == '%') 
        { 
            format++; 
            switch (*format) 
            { 
                case 'd': 
                { 
                    int arg = va_arg(args, int); 
                    int j = 0, k = arg; 
  
                    // Reverse the number 
                    while (k) 
                    { 
                        str[i++] = (k % 10) + '0'; 
                        k /= 10; 
                        j++; 
                    } 
  
                    // Reverse the string 
                    for (j = j - 1; j >= 0; j--, i++) 
                        str[i] = str[i - j - 1]; 
                    break; 
                } 
  
                case 's': 
                { 
                    char *arg = va_arg(args, char *); 
                    int j = 0; 
  
                    // Copy the string 
                    while (arg[j] != '\0') 
                        str[i++] = arg[j++]; 
                    break; 
                } 
            } 
        } 
        else
            str[i++] = *format; 
  
        format++; 
    } 
    va_end(args); 
  
    // Add null terminator 
    str[i] = '\0'; 
  
    return i; 
}

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
                _sprintf(str, "%s=%s", name, value); 
  
                // Replace the existing string with the new one 
                environ[i] = str; 
            } 
  
            // Variable is changed or added 
            return 0; 
        } 
    } 
  
    // Variable not found, so add it 
    environ[i] = (char *)malloc(strlen(name) + strlen(value) + 2); 
    _sprintf(environ[i], "%s=%s", name, value); 
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
