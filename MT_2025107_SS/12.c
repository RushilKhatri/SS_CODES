/*
============================================================================
Name :12.c
Author : Rushil Khatri
Description : a program to find out the opening mode of a file. Use fcntl.
Date: 6th Sept, 2025.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void) {
int fd = open("mode.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
int flags = fcntl(fd, F_GETFL);
int access = flags & O_ACCMODE;
printf("Access mode: %s\n", access==O_RDONLY? "O_RDONLY" : access==O_WRONLY? "O_WRONLY" : "O_RDWR");
printf("append: %s\n", (flags & O_APPEND) ? "ON" : "OFF");
printf("nonblock: %s\n", (flags & O_NONBLOCK) ? "ON" : "OFF");
printf("sync: %s\n", (flags & O_SYNC) ? "ON" : "OFF");
close(fd);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Access mode: O_RDWR
append: OFF
nonblock: OFF
sync: OFF
============================================================================
*/
