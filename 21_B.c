/*
============================================================================
Name : 21_B.c
Author : Rushil Khatri
Description : Write two programs so that both can communicate by FIFO -Use two way communications..

Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo_write = "fifo2"; // send to A
    const char *fifo_read = "fifo1";  // receive from A
    char buffer[100];

    while (1) {
        int fd_A = open(fifo_read, O_RDONLY);
        read(fd_A, buffer, sizeof(buffer));
        printf("A messaged : %s", buffer);
        close(fd_A);

        printf("Enter message(A to B): ");
        fgets(buffer, sizeof(buffer), stdin);
        int fd_B = open(fifo_write, O_WRONLY);
        write(fd_B, buffer, strlen(buffer)+1);
        close(fd_B);
    }

    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques21$ ./21_B
A messaged : Hello from A
Enter message(A to B): HII from B
====================================================================================
*/