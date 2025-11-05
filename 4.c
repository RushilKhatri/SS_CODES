/*
============================================================================
Name : 4.c
Author : Rushil Khatri
Description :a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.  
Date: 20th October 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdint.h>
static inline uint64_t rdtsc() {
    unsigned hi, lo;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}
int main()
{
    uint64_t start,end,diff;
    pid_t p;
    start=rdtsc();
    for(int i=0;i<100;i++)
    {
        p=getppid();
    }
    end=rdtsc();
    diff=end-start;
    printf("total cycles for 100 calls : %lld",(long long)diff);
    return 0;
}

/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques4$ ./4
total cycles for 100 calls : 121304
====================================================================================
*/