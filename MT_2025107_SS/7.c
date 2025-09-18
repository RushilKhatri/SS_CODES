/*
============================================================================
Name :7.c
Author : Rushil Khatri
Description : a program to copy file1 into file2
Date: 6th Sept, 2025.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
int main(int argc, char *argv[]) {
 int in = open(argv[1], O_RDONLY);
 int out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
 char buf[65536];
 while (1) {
 ssize_t n = read(in, buf, sizeof(buf));
 if (n == 0) break;
 ssize_t off = 0;
 while (off < n) {
 ssize_t m = write(out, buf + off, n - off);
 off += m;
 }
 }
 close(in); close(out);
 return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
./7 file1.txt file2.txt

file1.txt contains
Hello my name is Rushil Khatri
copied to file2.txt
Hello my name is Rushil Khatri
============================================================================
*/
