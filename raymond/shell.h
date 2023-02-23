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

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strstr(char *haystack, char *needle);
char *_strcat(char *, char *);
char *_strchr(char *s, char c);

/* string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
int _sprintf(char *str, const char *format, ...);

/* mem_mgt.c */
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int nmemb, unsigned int size);

/* printenviron.c */
void printenviron(char **ev);

/* tok.c */
char **tokenize(char *str, const char *delim);

/* _error.c */
void _error(char ***argv, char **arg);

#endif
