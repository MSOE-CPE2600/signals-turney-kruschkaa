/**
 * File: send_signal.c
 * Modified by: Alexander Kruschka
 * Assignment: Lab 10
 * Section: 111
 * 
 * Brief summary of program: Sends a random integer value using the sigqueue function
 *  to another proram specified by the user entered PID in the command line with SIGUSR1.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Initialize variables and unions
    union sigval rand_val;
    int pid_dest;

    // Get a random value to be sent
    srand(time(NULL));
    rand_val.sival_int = rand();

    // Error check for entered parameters
    if (argc < 2)
    {
        printf("Error, enter a PID as a destination for the signal.\n");
        exit(EXIT_FAILURE);
    }
    
    // Error check for non-integer input
    if ((pid_dest = atoi(argv[1])) == -1)
    {
        printf("Error, please enter a valid integer.\n");
        exit(EXIT_FAILURE);
    }

    // Error check for sending signal and send if valid
    if (sigqueue(pid_dest, SIGUSR1, rand_val) == -1)
    {
        printf("Error sending signal to entered PID, likely invalid PID.\n");
        exit(EXIT_FAILURE);
    }

    // If all successful, print confirmation message with sent integer
    printf("Sending %d with SIGUSR1 signal to PID: %d\n", rand_val.sival_int, pid_dest);

    // Exit program
    return 0;
}