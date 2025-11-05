/*
============================================================================
Name : 15.c
Author : Rushil Khatri
Description : a simple program to send some data from parent to the child process
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int fd[2]; 
    pid_t pid;
    char wrt[] = "This message is written by the parent";
    char rd[100];
    pipe(fd);
    pid = fork();
    if (pid > 0) 
    {
        close(fd[0]);
        printf("Parent: %s\n", wrt);
        write(fd[1], wrt, strlen(wrt) + 1); 
        close(fd[1]); 
    } 
    else 
    {
        close(fd[1]); 
        read(fd[0], rd, sizeof(rd));
        printf("Child: %s\n", rd);
        close(fd[0]);
    }
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques15$ ./15
Parent: This message is written by the parent
Child: This message is written by the parent
====================================================================================
*/