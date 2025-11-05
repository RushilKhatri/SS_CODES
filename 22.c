/*
============================================================================
Name : 22.c
Author : Rushil Khatri
Description : a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.

Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main() 
{
    const char *fifo = "myfifo";
    char buffer[100];
    int fd = open(fifo, O_RDONLY | O_NONBLOCK);
    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;  
    timeout.tv_usec = 0;

    printf("Waiting for data until 10 seconds\n");

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);
    if (ret == 0) 
    {
        printf("Timeout! No data was written within 10 seconds.\n");
    } 
    else 
    {
        if (FD_ISSET(fd, &readfds)) 
        {
            int n = read(fd, buffer, sizeof(buffer)-1);
            if (n > 0) 
            {
                buffer[n] = '\0';
                printf("Received: %s\n", buffer);
            }
            else 
            {
                printf("FIFO opened but no data received.\n");
            }
        }
    }

    close(fd);
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques22$ ./22
Waiting for data until 10 seconds
Received: Hello from writer
====================================================================================
*/
