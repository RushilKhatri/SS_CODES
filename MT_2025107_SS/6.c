/*
============================================================================
Name :6.c
Author : Rushil Khatri
Description : a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 6th Sept, 2025.
============================================================================
*/

#include<unistd.h>
int main(void)
{
char buf[4096];
ssize_t siz=read(0,buf,sizeof(buf));
if(siz==0) break;
if(siz<0) return 1;
ssize_t offset=0;
while(offset<siz)
{
ssize_t x=write(1,buf+offset,siz-offset);
if(x<=0)return 1;
offset+=x;
}
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
this text will be written 
this text will be written
============================================================================
*/

