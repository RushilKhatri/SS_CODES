/*
============================================================================
Name :14.c
Author : Rushil Khatri
Description :a program to find the type of a file.
    a. Input should be taken from command line.
    b. program should be able to identify any type of a file
Date: 6th Sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
struct stat set1;
mode_t t=set1.st_mode & S_IFMT;
const char *type="unknown";
if(S_ISREG(set1.st_mode))type="regular file";
else if(S_ISDIR(set1.st_mode)) type="directory";
else if(S_ISLNK(set1.st_mode)) type="symlink";
else if(S_ISCHR(set1.st_mode)) type="char device";
else if(S_ISBLK(set1.st_mode)) type="block device";
else if(S_ISFIFO(set1.st_mode)) type="FIFO";
else if(S_ISSOCK(set1.st_mode)) type="socket";
printf("%s\n",type);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
./14 /bin/ls
regular file
============================================================================
*/

