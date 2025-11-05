/*
============================================================================
Name : 19.c
Author : Rushil Khatri
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.

Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    /*const char *fifo_name = "mknod_fifo";
    mknod(fifo_name, S_IFIFO | 0666, 0); 
    printf("%s created using mknod\n", fifo_name);
    */
    const char *fifo_name = "mkfifo";
    mkfifo(fifo_name, 0666);
    printf("%s created using mkfifo\n", fifo_name);
    
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques19$ ./19
mknod_fifo created using mknod

rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques19$ ./19
mkfifo created using mknod

====================================================================================
*/