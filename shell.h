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

/*macros*/
#define MAXLEN 4096
#define PROMPT "#rsh$ "

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
