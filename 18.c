/*
============================================================================
Name : 18.c
Author : Rushil Khatri
Description : a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

Date: 20th October 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);
    pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]); 
        close(pipe2[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep");
        exit(1);
    }

    pid_t pid3 = fork();
    {
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("wc", "wc", NULL);
        exit(1);
    }
    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques18$ ./18
      1       9      54
====================================================================================
*/