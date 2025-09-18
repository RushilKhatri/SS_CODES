/*
============================================================================
Name :1.c
Author : Rushil Khatri
Description : Create the following types of a files using (i) shell command (ii) system call
                a. soft link (symlink system call)
                b. hard link (link system call)
                c. FIFO (mkfifo Library Function or mknod system call)
Date: 6th Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <errno.h>
#include <string.h>
int main(void) {
 if (symlink("original.txt", "softlink_to_original.txt") != -1) {
 printf("Soft link created.\n");
 }
 if (link("original.txt", "hardlink_to_original.txt") != -1) {
 printf("Hard link created.\n");
 }
 if (mkfifo("mypipe", 0666) != -1) {
 printf("FIFO created.\n");
 }
 return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-

Soft link created.
Hard link created.
FIFO created.
============================================================================
*/
