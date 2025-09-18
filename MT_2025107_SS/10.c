/*
============================================================================
Name :10.c
Author : Rushil Khatri
Description : a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
    a. check the return value of lseek
    b. open the file with od and check the empty spaces in between the data.
Date: 6th Sept, 2025.
============================================================================
*/
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main (void)
{
int fd=open("sparse.bin", O_WRONLY|O_CREAT|O_TRUNC,0644);
write(fd,"AAAAAAAAAA",10);
off_t off=lseek(fd,10,SEEK_CUR);// the lseek returns the new offset position in the file.
write(fd,"BBBBBBBBBB",10);
close(fd);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
./10
ls -ls sparse.bin
4 -rw-r--r-- 1 rushil rushil 30 Sep  7 13:07 sparse.bin
we only wrote 20 bytes of data but it shows that disk contains 30 bytes where 10 bytes is a hole
============================================================================
*/
