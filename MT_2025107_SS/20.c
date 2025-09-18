/*
============================================================================
Name :20.c
Author : Rushil Khatri
Description :Find out the priority of your running program.
Date: 6th Sept, 2025.
============================================================================
*/
#include<sys/time.h>
#include<sys/resource.h>
#include<stdio.h>
#include<unistd.h>
int main(void)
{
int pr=getpriority(PRIO_PROCESS,0);
printf("Current priority nice: %d\n",pr);
int rc=setpriority(PRIO_PROCESS,0,pr+5);
printf("New priority nice: %d\n",getpriority(PRIO_PROCESS,0));
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Current priority nice: 0
New priority nice: 5
============================================================================
*/
