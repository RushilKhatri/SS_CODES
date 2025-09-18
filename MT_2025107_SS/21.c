/*
============================================================================
Name :21.c
Author : Rushil Khatri
Description :A program, call fork and print the parent and child process id.
Date: 6th Sept, 2025.
============================================================================
*/
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(void)
{
pid_t pid=fork();
if(pid<0)
{
perror("fork");return 1;
}
if(pid==0)
{
printf("child id=%d, Parent id=%d\n",getpid(),getppid());
}
else
{
printf("child id=%d, Parent id=%d\n",pid,getpid());
}
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
child id=4089, Parent id=4088
child id=4089, Parent id=4088
============================================================================
*/
