/*
============================================================================
Name : 8_b.c
Author : Rushil Khatri
Description :   a separate program using signal system call to catch the following signals.
 a. SIGSEGV
 b. SIGINT
 c. SIGFPE
 d. SIGALRM (use alarm system call)
 e. SIGALRM (use setitimer system call)
 f. SIGVTALRM (use setitimer system call)
 g. SIGPROF (use setitimer system call)
Date: 20th October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void segint_handler(int sig) 
{
    printf("signal caught %d\n", sig);
    printf("exiting safely.\n");
    _exit(1); 
}
int main()
{
    signal(SIGINT, segint_handler);
    while (1) {
        printf("press Ctrl+C to stop\n");
        sleep(1);
    }
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques8$ ./8_b
press Ctrl+C to stop
press Ctrl+C to stop
press Ctrl+C to stop
^Csignal caught 2
exiting safely.
====================================================================================
*/