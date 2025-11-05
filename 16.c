/*
============================================================================
Name : 16.c
Author : Rushil Khatri
Description : a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int P2C[2]; 
    int C2P[2]; 
    pipe(P2C);
    pipe(C2P);
    pid_t pid = fork();
    if (pid == 0) {
        close(P2C[1]); 
        close(C2P[0]);
        char buffer[100];

        read(P2C[0], buffer, sizeof(buffer));
        printf("Parent wrote and child recieved: %s\n", buffer);
        char reply[] = "The child is replying";
        write(C2P[1], reply, strlen(reply) + 1);

        close(P2C[0]);
        close(C2P[1]);
    } else {
        close(P2C[0]);
        close(C2P[1]); 

        char message[] = "The message written by parent";
        write(P2C[1], message, strlen(message) + 1);
        char buffer[100];
        read(C2P[0], buffer, sizeof(buffer));
        printf("Reply of child received: %s\n", buffer);

        close(P2C[1]);
        close(C2P[0]);
    }

    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques16$ ./16
Parent wrote and child recieved: The message written by parent
Reply of child received: The child is replying
====================================================================================
*/