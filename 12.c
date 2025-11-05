/*
============================================================================
Name : 12.c
Author : Rushil Khatri
Description : a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int main()
{
    pid_t pid=fork();
    if(pid>0)
    {
        printf("Parent process with id %d will now be kiiled by the child process\n",getpid());
        sleep(10);
    }
    else
    {
        kill(getppid(),SIGKILL);
        sleep(4);
        printf("Childs new parent id is:%d \n", getppid());
        exit(0);
    }
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques12$ ./12
Parent process with id 10842 will now be kiiled by the child process
Killed
Childs new parent id is:1340 
====================================================================================
*/