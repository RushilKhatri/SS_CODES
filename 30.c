/*
============================================================================
Name : 30.c
Author : Rushil Khatri
Description :  Write a program to create a shared memory.
 a. write some data to the shared memory
 b. attach with O_RDONLY and check whether you are able to overwrite.
 c. detach the shared memory
 d. remove the shared memory
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() 
{
    key_t key;
    int shmid;
    char *shm_ptr;

    key = ftok("shmfile", 65); 
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);  
    printf("Shared memory created with ID: %d\n", shmid);
    shm_ptr = (char *)shmat(shmid, NULL, 0);
    printf("Writing data to shared memory...\n");
    strcpy(shm_ptr, "This is a sample data");
    printf("Data written: %s\n", shm_ptr);
    char *shm_ro_ptr = (char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Attached in read-only mode. Data: %s\n", shm_ro_ptr);
    shmdt(shm_ptr); 
    printf("Shared memory detached successfully.\n");

    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed successfully.\n");

    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques30$ ./30
Shared memory created with ID: 6
Writing data to shared memory...
Data written: This is a sample data
Attached in read-only mode. Data: This is a sample data
Shared memory detached successfully.
Shared memory removed successfully.
====================================================================================
*/