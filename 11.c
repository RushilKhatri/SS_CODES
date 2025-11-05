/*
============================================================================
Name : 11.c
Author : Rushil Khatri
Description : a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 20th October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main()
{
    struct sigaction sa;
    printf("press Ctrl+C \n");
    sa.sa_handler=SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;
    sigaction(SIGINT,&sa,NULL);
    sleep(4);
    printf("default action set. Ctrl+C to exit\n");
    sa.sa_handler=SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;
    sigaction(SIGINT,&sa,NULL);
    while(1)
    {
        pause();
    }
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques11$ ./11
press Ctrl+C 
^Cdefault action set. Ctrl+C to exit
====================================================================================
*/