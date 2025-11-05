/*
============================================================================
Name : 29.c
Author : Rushil Khatri
Description :  a program to remove the message queue.
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() 
{
    
    msgctl(2, IPC_RMID, NULL); 
    printf("Message queue (id=%d) removed successfully.\n", 2);

    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques29$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4106722c 0          rushil     666        0            0           
0x410671c5 1          rushil     666        200          2           
0xffffffff 2          rushil     340        0            0           

rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques29$ gcc 29.c -o 29

rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques29$ ./29
Message queue (id=2) removed successfully.

rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques29$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4106722c 0          rushil     666        0            0           
0x410671c5 1          rushil     666        200          2 
====================================================================================
*/