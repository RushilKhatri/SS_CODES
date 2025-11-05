/*
============================================================================
Name : 8_g.c
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
#include <sys/time.h>
#include <unistd.h>
void sigprof_handler(int sig) 
{
    printf("signal caught %d\n", sig);
    printf("exiting safely.\n");
    _exit(1); 
}
int main()
{
    struct itimerval timer;
    signal(SIGPROF, sigprof_handler);
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 500000;
    setitimer(ITIMER_PROF, &timer, NULL);
    printf("timer started\n");
    while(1) 
    {
        for(long i = 0; i < 1000000; i++); // consume CPU
    }
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques8$ ./8_g
timer started
signal caught 27
exiting safely.
====================================================================================
*/