/*
============================================================================
Name : 13_a.c
Author : Rushil Khatri
Description : two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigstop_handler(int sig)
{
    printf("Signal caught with number: %d\n", sig);
}

int main()
{
    signal(SIGSTOP, sigstop_handler);
    printf("Receiver PID: %d\n", getpid());
    while(1)
    {
        sleep(1);
    }
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:- 
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques13$ ./13_rec
Receiver PID: 11801
====================================================================================
*/