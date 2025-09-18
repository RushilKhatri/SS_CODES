/*
============================================================================
Name :5.c
Author : Rushil Khatri
Description : a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 6th Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
int fds[5];
const char *names[5]={"file1.txt", "file2.txt","file3.txt","file4.txt","file5.txt"};
for(int i=0;i<5;i++)
{
int fd=creat(names[i],0644);
fds[i]=fd;
}
while(1)
{sleep(5);}
return 0;
}

/*
============================================================================
SAMPLE OUTPUT:-
ls /proc/5320/fd
0  1  2  255
============================================================================
*/
