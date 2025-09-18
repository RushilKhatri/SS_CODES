/*
============================================================================
Name :3.c
Author : Rushil Khatri
Description : a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 6th Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>

int main(void)
{
int fd= creat("file1.txt", 0644);
printf("file Descriptor: %d\n", fd);
close(fd);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
file Descriptor: 3
============================================================================
*/
   
