#include "../shell.h"

int main(void)
{
	char *args1[] = {"exit", NULL};
	char *args2[] = {"env", NULL};
	char *args3[] = {"setenv", "VAR", "value", NULL};
	char *args4[] = {"unsetenv", "VAR", NULL};
	char *args5[] = {"help", NULL};
	char *args6[] = {"cd",  NULL};
	char *args7[] = {"ls", NULL};

	check_for_builtin(args2); /* Should print the environment variables */
	check_for_builtin(args3); /* Should set the environment variable VAR to value */
	check_for_builtin(args4); /* Should unset the environment variable VAR */
	check_for_builtin(args5); /* Should print help information */
	check_for_builtin(args6); /* Should change the current directory to /home/fourtythree43/*/
	check_for_builtin(args7); /* Should not do anything */
	//check_for_builtin(args1); /* Should exit the shell */
	return (0);
}
