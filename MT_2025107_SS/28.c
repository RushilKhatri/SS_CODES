/*
============================================================================
Name :28.c
Author : Rushil Khatri
Description :A program to get maximum and minimum real time priority
Date: 6th Sept, 2025.
============================================================================
*/
#include <sched.h>
#include <stdio.h>
int main(void) 
{
int mini = sched_get_priority_min(SCHED_FIFO);
int maxi = sched_get_priority_max(SCHED_FIFO);
printf("SCHED_FIFO min=%d max=%d\n", mini, maxi);
mini = sched_get_priority_min(SCHED_RR);
maxi = sched_get_priority_max(SCHED_RR);
printf("SCHED_RRmin=%d max=%d\n", mini, maxi);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
SCHED_FIFO min=1 max=99
SCHED_RRmin=1 max=99
============================================================================
*/

