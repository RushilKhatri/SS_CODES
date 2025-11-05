/*
============================================================================
Name : 31.c
Author : Rushil Khatri
Description :  Write a program to create a semaphore and initialize value to the semaphore.
 a. create a binary semaphore
 b. create a counting semaphore
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// Union required for semctl initialization
union semun {
    int val; 
    struct semid_ds *buf;    
    unsigned short *array;   
};

int main() 
{
    key_t key;
    int semid;
    union semun sem_union;

    key = ftok("semfile", 65);

    semid = semget(key, 1, 0666 | IPC_CREAT);

    sem_union.val = 1;
    semctl(semid, 0, SETVAL, sem_union);
    printf("Binary semaphore created. ID = %d, initial value = 1\n", semid);
    key_t count_key = ftok("semfile", 66);
    int count_semid = semget(count_key, 1, 0666 | IPC_CREAT);
    sem_union.val = 5;
    semctl(count_semid, 0, SETVAL, sem_union);
    printf("Counting semaphore created. ID = %d, initial value = 5\n", count_semid);

    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques31$ ./31
Binary semaphore created. ID = 1, initial value = 1
Counting semaphore created. ID = 2, initial value = 5
====================================================================================
*/