#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

/* Header Files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* Function Prototypes */
char **tokenize(char *str, const char *delim);
char *_getenv(const char *name);
void print_path(void);

struct path_list{
	char *dir_node;
	struct path_list *next;
};
typedef struct path_list path_list;

#endif /* MAIN_H */