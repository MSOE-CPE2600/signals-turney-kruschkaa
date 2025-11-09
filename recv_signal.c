/**
 * File: recv_signal.c
 * Modified by: Alexander Kruschka
 * 
 * Brief summary of program: Initializes and uses a sigusr1 handler that prints out an attached
 *  sival_int value to the console in an infinite loop until forcefully exited.
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigusr1(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1)
    {
        printf("Recieved SIGUSR1 with sival_int value: %d\n", info->si_value.sival_int);
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