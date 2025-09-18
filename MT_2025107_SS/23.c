/*
============================================================================
Name :23.c
Author : Rushil Khatri
Description :A program to create a Zombie state of the running program
Date: 6th Sept, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main(void)
{
pid_t pid=fork();
if(pid==0)
{
_exit(0);
}
else if(pid>0)
{
printf("Parent id=%d child id=%d\n",getpid(),pid);
sleep(20);
}
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Parent id=4231 child id=4232
Only parent id is remaining in the program.
============================================================================
*/
