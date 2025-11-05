/*
============================================================================
Name : 20_r.c
Author : Rushil Khatri
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo = "myfifo";
    char buffer[100];
    int fd = open(fifo, O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);

    close(fd);
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques20$ ./20_r
Received message: Hello from one end
====================================================================================
*/