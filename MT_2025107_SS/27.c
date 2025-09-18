/*
============================================================================
Name :27.c
Author : Rushil Khatri
Description :A program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 6th Sept, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main(void) {
char *argv[] = {"ls", "-Rl", NULL};
char *envp[] = {"LANG=C", NULL};
execvp("ls", argv);
perror("exec* failed");
return 1;
}
/*
============================================================================
SAMPLE OUTPUT:-
total 20
-rwxrwxr-x 1 rushil rushil 16064 Sep  6 22:59 27
-rw-rw-r-- 1 rushil rushil   181 Sep  6 22:59 27.c
============================================================================
*/
