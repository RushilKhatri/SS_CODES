/*
============================================================================
Name :16.c
Author : Rushil Khatri
Description :a program to perform mandatory locking.
    a. Implement write lock
    b. Implement read lock
Date: 6th Sept, 2025.
============================================================================
*/
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
static int lock_reg(int filed, short type, off_t start, off_t len)
{
struct flock f1={0};
f1.l_type=type;
f1.l_whence=SEEK_SET;
f1.l_start=start;
f1.l_len=len;
return fcntl(filed,F_SETLKW,&f1);
}
int main(void)
{
int filed=open("file1.txt",O_RDWR|O_CREAT, 0644);
if(lock_reg(filed,F_WRLCK,0,0)<0){perror("write lock"); return 1;}
sleep(15);
lock_reg(filed,F_UNLCK,0,0);
close(filed);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
When we run this code it set a write a lock on the file1.txt and then sleep for 15 sec
now when we try to access this file from another terminal it waits till the lock is unlocked
on the file1.txt then it can open the file1.txt
============================================================================
*/