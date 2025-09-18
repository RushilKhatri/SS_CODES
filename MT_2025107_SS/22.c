/*
============================================================================
Name :22.c
Author : Rushil Khatri
Description :A program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 6th Sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
int main(void)
{
int filed=open("file1.txt",O_WRONLY|O_TRUNC|O_CREAT,0644);
pid_t pid=fork();
if(pid==0)
{
write(filed,"this is written from the child process\n",38);
printf("This is written from the child process\n");
}
else
{
write(filed,"this is written from the parent process\n",39);
printf("this is written from the parent process\n");
}
close(filed);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
this is written from the parent process
This is written from the child process
============================================================================
*/