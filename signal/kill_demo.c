#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void handle_signal(int sig) {
    if (sig == SIGTERM) {
        printf("My mom killed me. So sad, bye mom, still love you...\n");
        exit(0);
    }
}

int main() {
    pid_t pid = fork();  // Create a child process
    
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    
    if (pid == 0) {
        // Child process
        signal(SIGTERM, handle_signal);  // Set up signal handler
        printf("I am Child process running with PID %d, my parent is %d, I have a very happy life\n", 
            getpid(), getppid());
        while (1) {
            // Simulate a long-running process
            sleep(1);
        }
    } else {
        // Parent process
        printf("I am Parent process running with PID %d, I am about to do something\n", getpid());
        sleep(3);  // Let the child process run for a while
        printf("Sending SIGTERM to kill my child %d ha ha ha\n", pid);
        kill(pid, SIGTERM);  // Send SIGTERM to the child process
        wait(NULL);  // Wait for the child process to terminate
        printf("My child %d was killed, enjoy watching right?\n", pid);
    }
    
    return 0;
}
