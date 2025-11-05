/*
============================================================================
Name : 33_r.c
Author : Rushil Khatri
Description :  a program to communicate between two machines using socket.
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    char *msg = "This message is from client";
    send(sock, msg, strlen(msg), 0);

    read(sock, buffer, sizeof(buffer));
    printf("Message recievd from server: %s\n", buffer);

    close(sock);
    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques33$ ./33_r
Message recievd from server: The message from server
====================================================================================
*/