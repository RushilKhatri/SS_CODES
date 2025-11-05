/*
============================================================================
Name : 1.c
Author : Rushil Khatri
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
 a. ITIMER_REAL
 b. ITIMER_VIRTUAL
 c. ITIMER_PROF
Date: 20th October 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>
void timer_handler(int signum)
{
    printf("timer has expired, the signal number is %d\n",signum);
}
int main()
{
    struct itimerval timer;
    signal(SIGALRM, timer_handler);
    timer.it_value.tv_sec=10;
    timer.it_value.tv_usec=10;
    timer.it_interval.tv_sec=10;
    timer.it_interval.tv_usec=10;
    setitimer(ITIMER_REAL,&timer,NULL);
    printf("itimer alarm started waiting for sigalarm\n");
    while(1)pause();
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques1$ ./1
itimer alarm started waiting for sigalarm
timer has expired, the signal number is 14
timer has expired, the signal number is 14
timer has expired, the signal number is 14
====================================================================================
*/
