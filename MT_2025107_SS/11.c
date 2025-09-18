/*
============================================================================
Name :11.c
Author : Rushil Khatri
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 6th Sept, 2025.
============================================================================
*/
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(void)
{
int fd=open("file1.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
int fd_1=dup(fd);
int fd_2=dup2(fd,10);
int flags=fcntl(fd,F_GETFL);
if(fcntl(fd,F_SETFL,flags | O_APPEND)<0){return 1;}
write(fd,"A",1);
write(fd_1,"B",1);
write(fd_2,"C",1);
close(fd);
close(fd_1);
close(fd_2);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
00000000  41 42 43 |ABC|
00000003

============================================================================
*/
