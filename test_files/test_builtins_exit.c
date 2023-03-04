#include "../shell.h"

int main(void)
{
	char *args1[] = {"exit", "0", NULL};
	char *args2[] = {"exit", "123", NULL};

	/* Test exit with no arguments */
	shell_exit(args1);
	/* This should exit the shell with status code 0 */

	/* Test exit with argument */
	shell_exit(args2);
	/* This should exit the shell with status code 123 */

	return (0);
}
