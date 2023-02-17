#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char* command = NULL;
    size_t command_size = 0;
    
    while (1) {
        printf("#cisfun$ ");
        if (getline(&command, &command_size, stdin) == -1) {
            break;
        }
        
        // Remove the trailing newline character from the command string
        command[strcspn(command, "\n")] = '\0';
        
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            
            // Parse the command and arguments
            char* tokens[MAX_COMMAND_LENGTH];
            char* token = strtok(command, " ");
            int i = 0;
            while (token != NULL) {
                tokens[i++] = token;
                token = strtok(NULL, " ");
            }
            tokens[i] = NULL;  // Set the last argument to NULL
            
            // Execute the command with its full path
            if (execv(tokens[0], tokens) == -1) {
                perror("execv");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            
            // Wait for the child process to complete
            if (wait(NULL) == -1) {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }
    
    free(command);
    return 0;
}
