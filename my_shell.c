#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

// Function to display the shell prompt
void display_prompt() {
    printf("my_shell> ");
}

// Function to read user input
char* read_input() {
    char* input = NULL;
    size_t input_length = 0;
    getline(&input, &input_length, stdin);
    return input;
}

// Function to execute a command
void execute_command(char* command) {
    char* args[MAX_COMMAND_LENGTH];
    int arg_count = 0;

    // Tokenize the command string into arguments
    char* token = strtok(command, " n");
    while (token != NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " n");
    }
    args[arg_count] = NULL;

    // Execute the command using execve
    execve(args[0], args, NULL);

    // If execve returns, there was an error
    printf("Error executing command: %sn", command);
    exit(1);
}

// Main function
int main() {
    while (1) {
        display_prompt();

        // Read user input
        char* input = read_input();

        // Check if the user wants to exit
        if (strcmp(input, "exitn") == 0) {
            free(input);
            break;
        }

        // Fork a child process to execute the command
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execute_command(input);
        } else if (pid > 0) {
            // Parent process
            wait(NULL);
        } else {
            // Fork error
            printf("Error forking processn");
            exit(1);
        }

        free(input);
    }

    return 0;
}
