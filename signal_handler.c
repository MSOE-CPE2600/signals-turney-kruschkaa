/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 * Kill process with ctrl + c or typing kill -s SIGINT <PID> in terminal
 */

/**
 * Modified by: Alexander Kruschka
 * 
 * Brief summary of modifications:
 * - Added volatile variable to determine whether to quit or not
 * - Signal handler now changes the run to false instead of exiting program
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

volatile int run = 1;

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    run = 0;
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received, checking if program should quit
    while(1) {
        printf("Sleeping\n");
        sleep(1);
        if (run == 0)
        {
            break;
        }
    }

    printf("Exiting outside of handler.\n");

    return 0;
}