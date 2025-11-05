
/*
============================================================================
Name : 34.c
Author : Rushil Khatri
Description :  a program to communicate between two machines using socket.
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 8080

void handle_client(int client_sock) 
{
    char buffer[1024];
    int n;
    while ((n = read(client_sock, buffer, sizeof(buffer))) > 0) 
    {
        buffer[n] = '\0';
        printf("Client side: %s\n", buffer);
        send(client_sock, buffer, strlen(buffer), 0);
    }
    close(client_sock);
    printf("Client disconnected.\n");
}

void* thread_func(void* arg) 
{
    int client_sock = *(int*)arg;
    free(arg);
    handle_client(client_sock);
    return NULL;
}

int main() 
{
    int server_fd, *client_sock, mode;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);

    printf("Choose mode:\n1. fork\n2. pthread\n ");
    scanf("%d", &mode);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 5);
    printf("Server running on port number %d\n", PORT);

    while (1) 
    {
        client_sock = malloc(sizeof(int));
        *client_sock = accept(server_fd, (struct sockaddr*)&addr, &addrlen);

        if (mode == 1) 
        {
            if (fork() == 0) 
            {
                close(server_fd);
                handle_client(*client_sock);
                exit(0);
            }
            close(*client_sock);
            free(client_sock);
        } 
        else 
        {  // pthread mode
            pthread_t tid;
            pthread_create(&tid, NULL, thread_func, client_sock);
            pthread_detach(tid);
        }
    }
    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques34$ ./34
Choose mode:
1. fork
2. pthread
 1
Server running on port number 8080
Client side: This message is from client
Client disconnected.

====================================================================================
*/