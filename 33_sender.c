/*
============================================================================
Name : 33_s.c
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

int main() 
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    listen(server_fd, 3);
    printf("Server listening on port %d\n", PORT);

    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    printf("Connection established\n");

    read(new_socket, buffer, sizeof(buffer));
    printf("Message from receiver: %s\n", buffer);

    char *msg = "The message from server";
    send(new_socket, msg, strlen(msg), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques33$ ./33_s
Server listening on port 8080
Connection established
Message from receiver: This message is from client
====================================================================================
*/