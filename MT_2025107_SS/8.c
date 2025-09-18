
/*
============================================================================
Name :8.c
Author : Rushil Khatri
Description : a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 6th Sept, 2025.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
FILE *fp=fopen(argv[1],"r");
char *line=NULL;
size_t cap=0;
ssize_t n;
while((n=getline(&line,&cap,fp))!=-1)
{
fwrite(line,1,n,stdout);
}
free(line);
fclose(fp);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
./8 files.txt

Hello there 
my name is rushil khatri
I'm 22 years old
============================================================================
*/


