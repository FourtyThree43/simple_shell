#include "../shell.h"
#include <stdio.h>

int main(void)
{
	printf("Testing get_input function...\n");
	char *input = get_input();
    printf("Input: %s\n", input);
    free(input);
}
