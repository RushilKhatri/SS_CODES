/*
============================================================================
Name : 23.c
Author : Rushil Khatri
Description : a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
system call with FIFO.

Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Maximum number of files a process can open: soft=%ld, hard=%ld\n",rl.rlim_cur, rl.rlim_max);
    int pipefd[2];
    pipe(pipefd);
    long pipe_size = fpathconf(pipefd[0], _PC_PIPE_BUF);
    printf("Buffer size of the pipe= %ld bytes\n", pipe_size);
    close(pipefd[0]);
    close(pipefd[1]);
    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques23$ ./23
Maximum number of files a process can open: soft=1024, hard=1048576
Buffer size of the pipe= 4096 bytes
====================================================================================
*/
