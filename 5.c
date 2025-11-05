/*
============================================================================
Name : 5.c
Author : Rushil Khatri
Description :program to print the system limitation of
 a. maximum length of the arguments to the exec family of functions.
 b. maximum number of simultaneous process per user id.
 c. number of clock ticks (jiffy) per second.
 d. maximum number of open files
 e. size of a page
 f. total number of pages in the physical memory
 g. number of currently available pages in the physical memory. 
Date: 20th October 2025
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main()
{
    long val;
    val=sysconf(_SC_ARG_MAX);
    printf("Maximim length of argument is :%ld\n", val);
    val=sysconf(_SC_CHILD_MAX);
    printf("Maximum process per child: %ld\n",val);
    val=sysconf(_SC_CLK_TCK);
    printf("Clock ticks per second: %ld\n",val);
    val=sysconf(_SC_OPEN_MAX);
    printf("Maximum open files: %ld\n",val);
    val=sysconf(_SC_PAGESIZE);
    printf("Page size: %ld\n",val);
    val=sysconf(_SC_PHYS_PAGES);
    printf("Total physical pages: %ld\n",val);
    val=sysconf(_SC_AVPHYS_PAGES);
    printf("Available physical pages: %ld\n",val);
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques5$ ./5
Maximim length of argument is :2097152
Maximum process per child: 62169
Clock ticks per second: 100
Maximum open files: 1024
Page size: 4096
Total physical pages: 4020072
Available physical pages: 2373966
====================================================================================
*/