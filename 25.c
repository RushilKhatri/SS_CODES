/*
============================================================================
Name : 25.c
Author : Rushil Khatri
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20th October 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() 
{
    key_t key;
    int msgid;
    struct msqid_ds buf;
    key = ftok("progfile", 65);

    msgid = msgget(key, 0666);

    msgctl(msgid, IPC_STAT, &buf);
    printf("Message Queue ID: %d\n", msgid);
    printf("Key: %d\n", key);

    printf("Access Permissions: %o\n", buf.msg_perm.mode);
    printf("UID: %d\n", buf.msg_perm.uid);
    printf("GID: %d\n", buf.msg_perm.gid);

    printf("Time of last message sent: %s", ctime(&buf.msg_stime));
    printf("Time of last message received: %s", ctime(&buf.msg_rtime));

    printf("Time of last change: %s", ctime(&buf.msg_ctime));

    printf("Current number of bytes in queue: %lu\n", buf.__msg_cbytes);

    printf("Number of messages in queue: %lu\n", buf.msg_qnum);

    printf("Max number of bytes allowed: %lu\n", buf.msg_qbytes);

    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques26$ ./26
Message Queue ID: -1
Key: 1090941381
Access Permissions: 0
UID: 0
GID: 2097152
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change: Thu Jan  1 05:30:00 1970
Current number of bytes in queue: 0
Number of messages in queue: 0
Max number of bytes allowed: 0
PID of last msgsnd: 0
PID of last msgrcv: 0
====================================================================================
*/