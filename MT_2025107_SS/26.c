/*
============================================================================
Name :26.c
Author : Rushil Khatri
Description :a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program.
Date: 6th Sept, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
int main(void)
{
printf("Will Exec now\n");
execl("/bin/echo","echo","Hello","World",NULL);
perror("execl");
return 1;
}

/*
============================================================================
SAMPLE OUTPUT:-
Will Exec now
Hello World
============================================================================
*/

