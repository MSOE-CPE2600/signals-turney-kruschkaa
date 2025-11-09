/**
 * File: signal_alarm.c
 * Modified by: Alexander Kruschka
 * 
 * Brief summary of program:
 * - Added a signal alarm to print a message
 * - Calls an alarm with a wait time of five seconds
 * - Waits for alarm to be called
 * - Exits program
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGALRM - prints a message
 */
void handle_sigalrm()
{
    printf("Alarm signal recieved!\n");
    return;
}

int main()
{
    // Signal register and wait time initialization
    signal(SIGALRM, handle_sigalrm);
    int wait_time = 5;

    printf("Waiting for %d seconds.\n", wait_time);

    // Set an alarm for 5 seconds
    alarm(wait_time);

    // Wait long enough for alarm to be triggered
    sleep(wait_time);

    // Quit program
    return 0;
}