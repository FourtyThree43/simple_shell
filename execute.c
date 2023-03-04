#include "shell.h"

/**
 * execute - Execute a command with arguments.
 * @argv: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int execute(char **argv)
{
	pid_t id;
	int wstatus, status = 0;
	char *cmd_path, *envp[] = { _getenv("PATH"), NULL };

	if (argv == NULL || *argv == NULL)
		return (status);
	if (check_for_builtin(argv))
		return (status);

	id = fork();
	if (id < 0)
	{
		_puterror("fork");
		return (1);
	}
	if (id == -1)
		perror(argv[0]), free_tokens(argv);
	if (id == 0)
	{
		cmd_path = NULL;
		if (argv[0][0] != '/')
			cmd_path = find_in_path(argv[0]);
		if (cmd_path == NULL)
			cmd_path = argv[0];
		if (execve(cmd_path, argv, envp) == -1)
			perror(argv[0]), free_tokens(argv), exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}
