 #include "shell.h"

/**
 * check_for_builtin - checks if the command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int check_for_builtin(char **args)
{
	if (!args[0])
		return (0);
	 if (!_strcmp(args[0], "exit"))
	 	shell_exit(EXIT_SUCCESS);
	// else if (!_strcmp(args[0], "env"))
	// 	print_env();
	else if (!_strcmp(args[0], "setenv"))
		set_env(args);
	else if (!_strcmp(args[0], "unsetenv"))
		unset_env(args);
	// else if (!_strcmp(args[0], "help"))
	// 	shell_help();
	else if (!_strcmp(args[0], "cd"))
		shell_cd(args);
	else
		return (0);
	return (1);
}
