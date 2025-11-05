/*
============================================================================
Name : 21_A.c
Author : Rushil Khatri
Description : WWrite two programs so that both can communicate by FIFO -Use two way communications..

Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo_write = "fifo1"; // send to B
    const char *fifo_read = "fifo2";  // receive from B
    char buffer[100];

    while (1) {
        printf("Enter message(from A to B): ");
        fgets(buffer, sizeof(buffer), stdin);
        int fd_A = open(fifo_write, O_WRONLY);
        write(fd_A, buffer, strlen(buffer)+1);
        close(fd_A);

        int fd_B = open(fifo_read, O_RDONLY);
        read(fd_B, buffer, sizeof(buffer));
        printf("B replied: %s", buffer);
        close(fd_B);
    }

    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques21$ ./21_A
Enter message(from A to B): Hello from A
B replied: HII from B
====================================================================================
*/