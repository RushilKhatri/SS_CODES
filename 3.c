/*
============================================================================
Name : 3.c
Author : Rushil Khatri
Description : a program to set (any one) system resource limit. Use setrlimit system call. 
Date: 20th October 2025
============================================================================
*/
#include<stdio.h>
#include<sys/resource.h>
int main()
{
    struct rlimit lim;
    getrlimit(RLIMIT_NOFILE, &lim);
    printf("Before setting the RLIMIT_NOFILE soft:%ld and hard: %ld\n",(long)lim.rlim_cur,(long)lim.rlim_max);
    lim.rlim_cur=lim.rlim_max;
    setrlimit(RLIMIT_NOFILE,&lim);
    getrlimit(RLIMIT_NOFILE,&lim);
    printf("Before setting the RLIMIT_NOFILE soft:%ld and hard: %ld\n",(long)lim.rlim_cur,(long)lim.rlim_max);
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques3$ ./3
Before setting the RLIMIT_NOFILE soft:1024 and hard: 1048576
Before setting the RLIMIT_NOFILE soft:1048576 and hard: 1048576
====================================================================================
*/