#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* Global Variables */
extern char **environ;

/* Structs */
/**
 * struct path_s - linked list of PATH directories
 * @dir: directory in PATH
 * @next: pointer to next node
 */
typedef struct path_s
{
	char *dir;
	struct path_s *next;
} path_t;

/* Function Prototypes */
/* prompt.c */
void print_prompt(void);

/* main.c */
char *read_line(void);
char **parse_line(char *line);
void execute(char **args);

/* builtins.c */
int shell_exit(char **args);
int shell_cd(char **args);
int shell_env(char **args);

/* path.c */
char *get_path(char **env);
void free_path_list(path_t *head);
path_t *path_list(char *path);

/* _getenv.c*/
char *_getenv(const char *name)

/* execute.c */
int execute(char **args, char *path);
int check_for_builtin(char **args);
char **tokenize(char *input, const char *delimiter);
void free_tokens(char **tokens);

/* helpers.c */
int _putchar(char c);
void _puts(char *str);
void _puterror(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

#endif
