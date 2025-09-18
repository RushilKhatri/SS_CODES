/*
============================================================================
Name :4.c
Author : Rushil Khatri
Description : a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 6th Sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(void)
{
int temp=creat("file1.txt",0644);
if(temp==-1)
{
perror("creat"); return 1;
}
int fd=open("file1.txt", O_RDWR);
write(fd,"Hello",5);
close(fd);
int fd2=open("file1.txt", O_CREAT| O_EXCL |O_RDWR,0644);
if(fd==-1)
{
printf("The execution failed: %s\n", strerror(errno));
}
else
{
printf("Execution succeded(file not exist)\n");
close(fd2);
}
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Execution succeded(file not exist)
============================================================================
*/




