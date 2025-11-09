/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Alexander Kruschka
 * Assignment: Lab 10
 * Section: 111
 * 
 * Brief summary of modifications:
 * - Added a signal handler for SIGSEGV that prints a message
 */

#include <signal.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message and returns without performing anything else
 */
void handle_sigsegv()
{
    printf("Segmentation fault has occured!\n");
    return;
}

int main (int argc, char* argv[]) {
    
    // Register for the signal
    signal(SIGSEGV, handle_sigsegv);
    
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}