/*
============================================================================
Name :29.c
Author : Rushil Khatri
Description : A program to get scheduling policy and modify the scheduling policy
Date: 6th Sept, 2025.
============================================================================
*/
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(void) 
{
struct sched_param sp = { .sched_priority = 10 };
sched_setscheduler(0, SCHED_RR, &sp);
int poll = sched_getscheduler(0);
printf("Policy now: %d (FIFO=%d RR=%d OTHER=%d)\n", poll, SCHED_FIFO, SCHED_RR, SCHED_OTHER);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Policy now: 2 (FIFO=1 RR=2 OTHER=0)
============================================================================
*/

