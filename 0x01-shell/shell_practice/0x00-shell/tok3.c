#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFSIZE 1024

/**
 * tokenize - tokenize a string into words
 *
 * Return: array of word pointers
 */
char **tokenize(void)
{
    char str[BUFFSIZE];
    char *token;
    char *s = " ";
    char **ret = NULL;
    int i = 0;

    if (fgets(str, BUFFSIZE, stdin) == NULL) {
        return NULL;
    }
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    token = strtok(str, s);
    while (token != NULL)
    {
        ret = realloc(ret, sizeof(char *) * (i + 1));
        if (ret == NULL)
        {
            dprintf(2, "Error: realloc() failure\n");
            exit(EXIT_FAILURE);
        }
        ret[i] = malloc(strlen(token) + 1);
        if (ret[i] == NULL)
        {
            dprintf(2, "Error: malloc() failure\n");
            exit(EXIT_FAILURE);
        }
        strcpy(ret[i], token);
        token = strtok(NULL, s);
        i++;
    }
    ret = realloc(ret, sizeof(char *) * (i + 1));
    if (ret == NULL)
    {
        dprintf(2, "Error: realloc() failure\n");
        exit(EXIT_FAILURE);
    }
    ret[i] = NULL;
    return ret;
}

/**
 * main - entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    char **arr = tokenize();
    int i;

    if (arr == NULL) {
        fprintf(stderr, "Error: fgets() failure\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; arr[i] != NULL; i++)
    {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);
    return EXIT_SUCCESS;
}
