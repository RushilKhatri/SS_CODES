/*
============================================================================
Name :25.c
Author : Rushil Khatri
Description :A program to create three child processes. The parent should wait for a particular child
Date: 6th Sept, 2025.
============================================================================
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main(void) {
pid_t p[3];
for (int i=0;i<3;i++) {
p[i] = fork();
if (p[i]==0) { sleep(2+i);_exit(10+i); }
}
// Wait only for the second child
int status;
pid_t w = waitpid(p[1], &status, 0);
if (w == p[1]) {
if (WIFEXITED(status)) printf("Child2 exited with %d\n", WEXITSTATUS(status));
}
// Reap remaining children
while (wait(NULL) > 0);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Child2 exited with 11
============================================================================
*/

