#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *args[] = {"cd", "..", NULL};
	shell_cd(args);

	args[0] = "setenv";
	args[1] = "SHELL";
	args[2] = "myshell";
	args[3] = NULL;
	set_env(args);

	args[0] = "unsetenv";
	args[1] = "SHELL";
	args[2] = NULL;
	unset_env(args);

	char *env[] = 
	{
        "USER=johndoe",
        "HOME=/home/johndoe",
        "PATH=/usr/local/bin:/usr/bin:/bin",
        NULL
    };

    print_env(env);

	args[0] = "exit";
	args[1] = NULL;
	shell_exit(EXIT_SUCCESS);

	return (0);
}
