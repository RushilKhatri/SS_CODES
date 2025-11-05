/*
============================================================================
Name : 24.c
Author : Rushil Khatri
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main() 
{
    key_t key;
    int msgid;

    // Generate unique key using ftok
    key = ftok("progfile", 65);  // "progfile" should exist in the current directory
    msgid = msgget(key, 0666 | IPC_CREAT);  // Permissions: read/write for all
    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques24$ ./24
Message Queue Key: 1090941484
Message Queue ID: 0
====================================================================================
*/