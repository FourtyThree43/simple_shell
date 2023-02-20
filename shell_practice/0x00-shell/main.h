#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

/* Header Files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct path_list{
	char *dir_node;
	struct path_list *next;
} path_list;

/* Function Prototypes */
char **tokenize(char *str, const char *delim);
char *_getenv(const char *name);
void print_path(void);
char **path_ptrs(void);
path_list *build_list(char **ptr);
void free_list(path_list *head, int tok);
int _setenv(const char *name, const char *value, int overwrite);

#endif /* MAIN_H */