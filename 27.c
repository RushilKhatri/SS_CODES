/*
============================================================================
Name : 27.c
Author : Rushil Khatri
Description : Write a program to receive messages from the message queue.
 a. with 0 as a flag
 b. with IPC_NOWAIT as a flag
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() 
{
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Choose receiving mode:\n");
    printf("1. Blocking (flag = 0)\n");
    printf("2. Non-blocking (flag = IPC_NOWAIT)\n");
    int choice;
    scanf("%d", &choice);
    getchar();

    int flag = 0;
    if (choice == 2)flag = IPC_NOWAIT;

    printf("Waiting for message...\n");
    ssize_t rcv_size = msgrcv(msgid, &message, sizeof(message.msg_text), 1, flag);
    printf("Message received: %s\n", message.msg_text);
    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques27$ ./27
Choose receiving mode:
1. Blocking (flag = 0)
2. Non-blocking (flag = IPC_NOWAIT)
1
Waiting for message...
Message received: Hello how are you
====================================================================================
*/
