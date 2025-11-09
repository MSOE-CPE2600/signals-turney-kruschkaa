/**
 * File: signal_sigaction.c
 * Modified by: Alexander Kruschka
 * Assignment: Lab 10
 * Section: 111
 * Note: Send SIGUSR1 signal via: kill -SIGUSR1 <pid>
 * 
 * Brief summary of program: Using a sigaction struct, initializes a handler for SIGUSR1
 *  to print out a message upon recieving the signal in an infinite waiting loop until
 *  forcefully exited.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/**
 * @brief Signal handler for SIGUSR1 - prints a message returns
 */
void handle_sigusr1(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1)
    {
        printf("Recieved SIGUSR1 from PID: %d\n", info->si_pid);
        return;
    }
}

int main()
{
    // Initialize sigaction struct
    struct sigaction sigact;
    sigact.sa_sigaction = handle_sigusr1;
    sigact.sa_flags = SA_SIGINFO;

    // Register signal handler for SIGUSR1
    sigaction(SIGUSR1, &sigact, NULL);

    // Enter indefinite loop for waiting
    printf("Program running and waiting for SIGUSR1 signal.\n");
    while (1)
    {
        sleep(1);
    }

    // Exit program
    return 0;
}
