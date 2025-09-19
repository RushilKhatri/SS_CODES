/*
============================================================================
Name :24.c
Author : Rushil Khatri
Description :A program to create an orphan process.
Date: 6th Sept, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include<sys/types.h>
int main(void) {
pid_t pid = fork();
if (pid == 0) {
sleep(6);
printf("Child ID=%d,Parent ID=%d\n", getpid(), getppid());
} else if (pid > 0) {
printf("Parent is exiting.\n");
_exit(0);
}
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Parent is exiting.
Child ID=4350,Parent ID=1420
============================================================================
*/
