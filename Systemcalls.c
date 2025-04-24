#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("Fork() failed...\n");
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        printf("Child PID: %d\n", getpid());
        
        // Replace child process with 'ls' command
        execlp("/bin/ls", "ls", "-l", NULL);  // Added -l for detailed listing
        
        // Only reaches here if execlp fails
        perror("execlp failed");
        exit(EXIT_FAILURE);
    } 
    else {
        // Parent process
        printf("Parent PID: %d\n", getpid());
        
        // Wait for child to complete
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
        printf("Parent: Child process completed\n");
    }

    return 0;
}
