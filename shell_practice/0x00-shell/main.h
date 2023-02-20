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
path_list *build_list(void);
void free_list(path_list *head);

#endif /* MAIN_H */