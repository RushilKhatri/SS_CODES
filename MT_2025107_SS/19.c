/*
============================================================================
Name :19.c
Author : Rushil Khatri
Description :a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 6th Sept, 2025.
============================================================================
*/
#define _GNU_SOURCE
#include<time.h>
#include<unistd.h>
#include<stdio.h>
static long long nsec_diff(struct timespec a,struct timespec b)
{
return (b.tv_sec-a.tv_sec)*1000000000LL +(b.tv_nsec-a.tv_nsec);
}
int main(void)
{
const int n=1000000;
struct timespec t1,t2;
clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
for(int i=0;i<n;i++)
{
getpid();
}
clock_gettime(CLOCK_MONOTONIC_RAW,&t2);
long long ns=nsec_diff(t1,t2);
printf("Total ns: %lld,Avg per call: %.2f ns\n", ns,(double)ns/n);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Total ns: 96214625,Avg per call: 96.21 ns
============================================================================
*/