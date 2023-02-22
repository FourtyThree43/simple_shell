#include "shell.h"

/**
 * check_for_builtin - checks if the command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int check_for_builtin(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	if (strcmp(*args, "exit") == 0)
		return (1);
	if (strcmp(*args, "cd") == 0)
		return (1);
	if (strcmp(*args, "env") == 0)
		return (1);
	return (0);
}

/**
 * execute - executes a command
 * @args: the arguments array
 * @path: the PATH variable
 *
 * Return: 1 on success, 0 on failure
 */
int execute(char **args, char *path)
{
	pid_t pid;
	char **tokens;
	char *command;
	int status;

	if (check_for_builtin(args))
		return (1);

	tokens = tokenize(path, ":");
	command = args[0];

	struct stat sb;
	int i = 0;
	char *dir;

	while (tokens[i] != NULL)
	{
		dir = malloc(_strlen(tokens[i]) + _strlen(command) + 2);
		_strcpy(dir, tokens[i]);
		_strcat(dir, "/");
		_strcat(dir, command);
		if (stat(dir, &sb) == 0 && sb.st_mode & S_IXUSR)
		{
			pid = fork();
			if (pid == -1)
				perror("Error");
			if (pid == 0)
			{
				if (execve(dir, args, environ) == -1)
				{
					_puterror("Error: Cannot execute command\n");
					free_tokens(tokens);
					free(dir);
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&status);
			free(dir);
			free_tokens(tokens);
			return (1);
		}
		i++;
		free(dir);
	}
	_puterror("Error: Command not found\n");
	free_tokens(tokens);
	return (0);
}

/**
 * tokenize - splits a string into tokens
 * @input: the input string
 * @delimiter: the delimiter character
 *
 * Return: an array of tokens
 */
char **tokenize(char *input, const char *delimiter)
{
	char **tokens = NULL;
	char *token;
	int i = 0;

	token = strtok(input, delimiter);
	while (token != NULL)
	{
		tokens = realloc(tokens, (i + 2) * sizeof(char *));
		if (tokens == NULL)
		{
			free_tokens(tokens);
			return (NULL);
		}
		tokens[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}


/**
 * free_tokens - frees an array of tokens
 * @tokens: the array of tokens
 */
void free_tokens(char **tokens)
{
	if (tokens == NULL)
		return;
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
