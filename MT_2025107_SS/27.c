/*
============================================================================
Name :27.c
Author : Rushil Khatri
Description :A program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 6th Sept, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main(void) {
char *argv[] = {"ls", "-Rl", NULL};
execvp("ls", argv);
//execv("/bin/ls", argv);
//execlp("ls", "ls", "-Rl", (char *)NULL);
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
