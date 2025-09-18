/*
============================================================================
Name :30.c
Author : Rushil Khatri
Description : A program to run a script at a specific time using a Daemon process
Date: 6th Sept, 2025.
============================================================================
*/
#define _XOPEN_SOURCE 700
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
static void daemonize(void) 
{
pid_t pid = fork(); if (pid < 0) exit(1); if (pid > 0) exit(0);
if (setsid() < 0) exit(1);
pid = fork(); if (pid < 0) exit(1); if (pid > 0) exit(0);
umask(027);
chdir("/");
int fd = open("/dev/null", O_RDWR);
dup2(fd, 0); dup2(fd, 1); dup2(fd, 2);
if (fd > 2) close(fd);
}
int main(int argc, char *argv[]) 
{
struct tm tm = {0};
if (!strptime(argv[1], "%Y-%m-%d %H:%M:%S", &tm)) { dprintf(2, "Bad time format\n"); return 1; }
time_t target = mktime(&tm);
daemonize();
for (;;) {
time_t now = time(NULL);
if (now >= target) break;
sleep(1);
}
execl("/bin/sh", "sh", argv[2], NULL);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
Hello! Task executed at Sun Sep  7 16:26:00 IST 2025
============================================================================
*/
