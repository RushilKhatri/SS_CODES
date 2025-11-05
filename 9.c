/*
============================================================================
Name : 9.c
Author : Rushil Khatri
Description : a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 20th October 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sigint_handler(int sig)
{
    printf("NOT TO BE PRINTED \n");
}

int main()
{
    printf("Press Ctrl+C now\n");
    signal(SIGINT, SIG_IGN);
    sleep(5);
    printf("SIGINT reseted to default action. Press Ctrl+C again to terminate.\n");
    signal(SIGINT, SIG_DFL);
    while(1) 
    {
        pause();
    }
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques9$ ./9
Press Ctrl+C now
^CSIGINT reseted to default action. Press Ctrl+C again to terminate.
^C  
====================================================================================
*/