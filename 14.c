/*
============================================================================
Name : 14.c
Author : Rushil Khatri
Description : a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
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
    char write_msg[] = "The message written using the pipe";
    char read_msg[80];
    pipe(fd);
    write(fd[1], write_msg, strlen(write_msg) + 1);
    printf("Data to be written: %s\n", write_msg);
    read(fd[0], read_msg, sizeof(read_msg));
    printf("Data readed by the pipe: %s\n", read_msg);
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques14$ ./14
Data to be written: The message written using the pipe
Data readed by the pipe: The message written using the pipe
====================================================================================
*/