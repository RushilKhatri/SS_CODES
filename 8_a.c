/*
============================================================================
Name : 8_a.c
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
void segv_handler(int sig) 
{
    printf("signal caught %d\n", sig);
    printf("seg_v action exit safely.\n");
    _exit(1); 
}
int main()
{
    signal(SIGSEGV, segv_handler);
    printf("Triggering SIGSEGV by dereferencing NULL...\n");
    int *p = NULL;
    *p = 22;
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques8$ ./8
Triggering SIGSEGV by dereferencing NULL...
signal caught 11
seg_v action exit safely.
====================================================================================
*/