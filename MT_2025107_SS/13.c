/*
============================================================================
Name :13.c
Author : Rushil Khatri
Description : a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 6th Sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<sys/select.h>
#include<unistd.h>
int main(void)
{
fd_set set1;
FD_ZERO(&set1);// initialising fd_set
FD_SET(0,&set1);//adding stdin
struct timeval t1={.tv_sec=10, .tv_usec=0};
int rc=select(1,&set1,NULL,NULL,&t1);
if(rc==0)
{
printf("data isn't provided within 10 seconds\n");
}
else
{
char buf[256];
ssize_t siz=read(0,buf,sizeof(buf));
if(siz>0) write(1,buf,siz);
}
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
if the data isn't provided in 10 sec

data isn't provided within 10 seconds

or else
hello
hello

the text is provided as output with STDOUT
============================================================================
*/


