/*
============================================================================
Name :18.c
Author : Rushil Khatri
Description :A program to perform Record locking.
    a. Implement write lock
    b. Implement read lock
Date: 6th Sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
static int critical_reg(int filed, short type,off_t start,off_t len)
{
struct flock f1={0};
f1.l_type=type;
f1.l_whence=SEEK_SET;
f1.l_start=start;
f1.l_len=len;
return fcntl(filed,F_SETLKW, &f1);
}
int main(void)
{
int filed=open("file1.txt",O_RDWR| O_CREAT, 0644);
ftruncate(filed,60);
if(critical_reg(filed,F_WRLCK,20,20)<0){perror("lock");return 1;}
lseek(filed,20,SEEK_SET);
write(filed,"Record updated\n",14);
sleep(15);
critical_reg(filed,F_UNLCK,20,20);
close(filed);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
./18
the content of the file1.txt looks like this
Record updated
============================================================================
*/