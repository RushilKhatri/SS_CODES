/*
============================================================================
Name : 17_a.c
Author : Rushil Khatri
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl

Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() 
{
    int pipefd[2];
    pipe(pipefd);
    pid_t pid1 = fork();
    if (pid1 == 0) 
    {
        close(pipefd[0]);
        close(1);                   
        dup(pipefd[1]);  
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }
    pid_t pid2 = fork();
    if (pid2 == 0) 
    {
        close(pipefd[1]);
        close(0); 
        dup(pipefd[0]);
        close(pipefd[0]);
        execlp("wc", "wc", NULL);
        exit(1);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques17$ ./17_a
      3      20     113
====================================================================================
*/