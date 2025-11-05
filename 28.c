/*
============================================================================
Name : 28.c
Author : Rushil Khatri
Description :  a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() 
{
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666);
    msgctl(msgid, IPC_STAT, &buf) ;
    printf("Current permission: %o\n", buf.msg_perm.mode);
    unsigned int new_mode;
    printf("Enter new permission: ");
    scanf("%o", &new_mode);
    buf.msg_perm.mode = new_mode;

    msgctl(msgid, IPC_SET, &buf);
    printf("Permissions changed to: %o\n", buf.msg_perm.mode);

    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques28$ ./28
Current permission: 666
Enter new permission: 340
Permissions changed to: 340
====================================================================================
*/