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
#define MAXLEN 4096
#define PROMPT "#rsh$ "

/* get_input.c */
char *get_path(void);

/* prompt.c */
void prompt(void);

/* str_funcs1.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strstr(char *haystack, char *needle);
char *_strcat(char *, char *);
char *_strchr(char *s, char c);

/* str_funcs2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
unsigned int _strspn(char *s, char *accept);

/* mem_funcs.c */
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int nmemb, unsigned int size);

/* print_env.c */
void print_env(char **ev);

/* tokenizer.c */
char **tokenize(char *str, const char *delim);

/* which.c */
char *which(char *filename, const char *path);

/* get_env.c */
char *_getenv(const char *name);

/* free.c */
void free_error(char **argv, char *arg);
void free_tok(char **ptr);

#endif
