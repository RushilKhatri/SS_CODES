/*
============================================================================
Name :2.c
Author : Rushil Khatri
Description : A simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory. mknod system call)
Date: 6th Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<time.h>
int main(void)
{
while(1)
{
time_t now=time(NULL);
printf("Still Running....%ld\n",(long)now);
fflush(stdout);
sleep(2);
}
}
/*
============================================================================
SAMPLE OUTPUT:-

Still Running....1757227517
Still Running....1757227519
Still Running....1757227521
Still Running....1757227523
ls /proc/4959/fd
0  1  2  255

============================================================================
*/
