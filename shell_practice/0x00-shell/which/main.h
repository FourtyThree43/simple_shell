#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

char *_getenv(const char *name);
char **tokenize(char *str, const char *delim);
void cleaner(char **ptr);

#endif /* MAIN_H */
