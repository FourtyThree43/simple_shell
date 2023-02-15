#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    printf("Before fork\n");

    pid = fork();
    if (pid == -1)
        perror("fork() failure");

    printf("After fork\n");
    return (0);
}
