/*
============================================================================
Name : 17_c.c
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
#include<fcntl.h>
#include <sys/wait.h>
int main() 
{
    int pipefd[2];
    pipe(pipefd);

    pid_t pid1 = fork();
    if (pid1 == 0) {
        close(pipefd[0]);
        int newfd = fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
        if (newfd != STDOUT_FILENO) {
            dup2(newfd, STDOUT_FILENO);
            close(newfd);
        }
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        close(pipefd[1]);
        int newfd = fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
        if (newfd != STDIN_FILENO) {
            dup2(newfd, STDIN_FILENO);
            close(newfd);
        }
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
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques17$ ./17_c
      7      56     321
====================================================================================
*/