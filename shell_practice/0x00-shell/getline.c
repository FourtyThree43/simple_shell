#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *line = NULL, *tmp = NULL;
	size_t len = 0;
	ssize_t nread;
	int i;

	if (argc != 1) {
		fprintf(stderr, "Usage: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("$ ");
	while ((nread = getline(&line, &len, stdin)) != -1) {
		if (strcmp(line, "exit\n") == 0){
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (nread == 1 && line[0] == 10)
		{
			printf("$ ");
			continue;
		}
		if (line[nread - 2] == '\\'){
			printf("> ");
			tmp = malloc(nread);
			if (tmp == NULL)
				exit(EXIT_FAILURE);
			for (i = 0; line[i]; i++)
				tmp[i] = line[i];
			continue;
		}
		if (tmp != NULL){
			for (i = 0; i < strlen(tmp); i++)
			{
				if ((tmp[i] == 92) && (tmp[i - 1] != 92))
					continue;
				putchar(tmp[i]);
			}
			free(tmp);
			tmp = NULL;
		}
		fwrite(line, 1, nread, stdout);
		printf("$ ");
	}
	free(line);
	putchar(10);
	exit(EXIT_SUCCESS);
}
