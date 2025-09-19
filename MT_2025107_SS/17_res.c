/*
============================================================================
Name :17_res.c
Author : Rushil Khatri
Description :A program to simulate online ticket reservation. Implement write lock
    Write a program to open a file, store a ticket number and exit. Write a separate program, to
    open the file, implement write lock, read the ticket number, increment the number and print
    the new ticket number then close the file.
Date: 6th Sept, 2025.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
static int lock_write(int fd) {
struct flock fl = {0};
fl.l_type = F_WRLCK;
fl.l_whence = SEEK_SET; 
fl.l_start = 0; 
fl.l_len = 0;
return fcntl(fd, F_SETLKW, &fl);
}
int main(void)
{
int fd = open("ticket.txt", O_RDWR);
lock_write(fd); 
char buf[64];
//reading the ticket number
lseek(fd, 0, SEEK_SET);
ssize_t n = read(fd, buf, sizeof(buf)-1);
buf[n] = '\0';
int t = atoi(buf);
t++;
// incremented the ticket number remove old add new ticket
lseek(fd, 0, SEEK_SET);
ftruncate(fd, 0);
dprintf(fd, "%d\n", t);
printf("New ticket number: %d\n", t);
// unlock the file for other user to use it
struct flock unl = {0};
unl.l_type = F_UNLCK; 
unl.l_whence = SEEK_SET;
fcntl(fd, F_SETLK, &unl);
close(fd);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
./17_res
New ticket number: 1001
It first get the lock then increase the ticket then write it in ticket.txt
then it unlock the lock for otheruser to use it
============================================================================
*/
