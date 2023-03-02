#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*macros*/
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "

// *
//  * struct bultin_s - struct for storing built-in commands
//  * @cmd: the name of the biult-in command.
//  * @func: a function pointer to the built-in commands's corresponing function.
//  *
//  * Description: This struct is used to store the built-in commands and their
//  *              corresponding function pointers in a linked list.
 
// typedef struct builtin_s
// {
// 	char *cmd;
// 	void (*func)(char **);
// };builtin_t;


/* get_input.c */
//char *get_input(void);

/* prompt.c */
//void prompt(void);

/* error.c */
void _puts(char *str);
void _puterror(char *err);

/* utils_funcs1.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strstr(char *haystack, char *needle);
char *_strcat(char *, const char *);
char *_strchr(char *s, char c);

/* utils_funcs2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
int _putchar(char);
unsigned int _strspn(char *s, char *accept);

/* utils_funcs3.c */
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int nmemb, unsigned int size);

/* print_env.c */
void print_env(char **ev);

/* tokenizer.c */
char **tokenize(char *str, const char *delim);

/* find_in_path.c */
char *find_in_path(char *command);

/* get_env.c */
char *_getenv(const char *name);

/* get_path.c */
char *get_path(void);

/* free.c */
void free_error(char **argv, char *arg);
void free_tokens(char **ptr);

#endif
