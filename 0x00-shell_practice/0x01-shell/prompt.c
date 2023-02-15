#include <stdio.h>
#include "shell.h"

void print_prompt1(void)
{
	fprintf(stderr, "$ ");
}

void print_prompt2(void)
{
	fprintf(stderr, "> ");
}
