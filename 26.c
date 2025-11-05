/*
============================================================================
Name : 26.c
Author : Rushil Khatri
Description :  a program to send messages to the message queue. Check $ipcs -q
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

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

    message.msg_type = 1;  
    printf("Enter a message: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);
    msgsnd(msgid, &message, sizeof(message.msg_text), 0);
    printf("Message sent to queue with key=%d and id=%d.\n", key, msgid);

    return 0;
}


/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques26$ ./26
Enter a message: Hello there
Message sent to queue with key=1090941381 and id=1.

rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4106722c 0          rushil     666        0            0           
0x410671c5 1          rushil     666        200          2  
====================================================================================
*/