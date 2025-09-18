/*
============================================================================
Name :17_init.c
Author : Rushil Khatri
Description :A program to simulate online ticket reservation. Implement write lock
    Write a program to open a file, store a ticket number and exit. Write a separate program, to
    open the file, implement write lock, read the ticket number, increment the number and print
    the new ticket number then close the file.
Date: 6th Sept, 2025.
============================================================================
*/
#include<fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void) 
{
int fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
dprintf(fd, "%d\n", 1000);
close(fd);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
when we run the init program it initialize the ticket.txt with 1000 written as the first ticket
============================================================================
*/
