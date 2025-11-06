/*
============================================================================
Name : 32.c
Author : Rushil Khatri
Description :  Write a program to implement semaphore to protect any critical section.
 a. rewrite the ticket number creation program using semaphore
 b. protect shared memory from concurrent write access
 c. protect multiple pseudo resources ( may be two) using counting semaphore
 d. remove the created semaphore
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
union semun { int val; struct semid_ds *buf; unsigned short *array; };
void sem_wait(int semid)
{ 
    struct sembuf sb = {0, -1, 0}; semop(semid, &sb, 1); 
}
void sem_signal(int semid) 
{
    struct sembuf sb = {0, 1, 0}; semop(semid, &sb, 1); 
}

int main() 
{
    key_t key = ftok("semfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    union semun u;

    int choice;
    printf("\nSemaphore Demo Menu\n");
    printf("1. Ticket number creation (binary)\n");
    printf("2. Protect shared memory writes\n");
    printf("3. Protect 2 resources (counting)\n");
    printf("4. Remove semaphore\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        u.val = 1; semctl(semid, 0, SETVAL, u);
        int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
        int *ticket = (int *)shmat(shmid, NULL, 0);
        for (int i = 0; i < 3; i++) {
            sem_wait(semid);
            (*ticket)++;
            printf("Process %d got ticket #%d\n", getpid(), *ticket);
            sem_signal(semid);
            sleep(1);
        }
        shmdt(ticket);
    }

    else if (choice == 2) {
        u.val = 1; semctl(semid, 0, SETVAL, u);
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
        char *str = (char *)shmat(shmid, NULL, 0);
        for (int i = 0; i < 3; i++) {
            sem_wait(semid);
            sprintf(str, "Process %d writing %d", getpid(), i);
            printf("Written: %s\n", str);
            sem_signal(semid);
            sleep(1);
        }
        shmdt(str);
    }

    else if (choice == 3) {
        u.val = 2; semctl(semid, 0, SETVAL, u);
        for (int i = 0; i < 2; i++) {
            sem_wait(semid);
            printf("Process %d acquired a resource...\n", getpid());
            sleep(2);
            printf("Process %d released resource\n", getpid());
            sem_signal(semid);
            sleep(1);
        }
    }

    else if (choice == 4) {
        semctl(semid, 0, IPC_RMID);
        printf("Semaphore removed.\n");
    }

    else {
        printf("Invalid choice\n");
    }

    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques32$ ./32
Semaphore Demo Menu
1. Ticket number creation (binary)
2. Protect shared memory writes
3. Protect 2 resources (counting)
4. Remove semaphore
Enter choice: 1
Process 4666 got ticket #1
Process 4666 got ticket #2
Process 4666 got ticket #4

rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques32$ ./32
Semaphore Demo Menu
1. Ticket number creation (binary)
2. Protect shared memory writes
3. Protect 2 resources (counting)
4. Remove semaphore
Enter choice: 1
Process 4667 got ticket #3
Process 4667 got ticket #5
Process 4667 got ticket #6
 
->If we don't use semaphores then processs might get same ticket numbers
====================================================================================
*/
