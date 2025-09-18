/*
============================================================================
Name :9.c
Author : Rushil Khatri
Description : a program to print the following information about a given file.
    a. inode
    b. number of hard links
    c. uid
    d. gid
    e. size
    f. block size
    g. number of blocks
    h. time of last access
    i. time of last modification
    j. time of last change
    Date: 6th Sept, 2025.
============================================================================
*/
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
#include<sys/stat.h>
static void print_time(const char *label, time_t t1)
{
char buf[64];
struct tm tm;
localtime_r (&t1,&tm);
strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",&tm);
printf("%s:%s\n",label,buf);
}
int main(int argc, char *argv[])
{
struct stat st;
struct passwd *pw=getpwuid(st.st_uid);
struct group *gr=getgrgid(st.st_gid);
printf("inode:%lu/n",(unsigned long)st.st_ino);
printf("hard links:%lu\n", (unsigned long)st.st_nlink);
printf("uid:%u(%s)\n", st.st_uid, pw ? pw->pw_name : "?");
printf("gid:%u(%s)\n", st.st_gid, gr ? gr->gr_name : "?");
printf("size:%lld bytes\n", (long long)st.st_size);
printf("block size:%ld\n", (long)st.st_blksize);
printf("blocks:%lld\n", (long long)st.st_blocks);
print_time("last access", st.st_atime);
print_time("last modification", st.st_mtime);
print_time("last status change", st.st_ctime);
return 0;
}
/*
============================================================================
SAMPLE OUTPUT:-
inode:7340032
hard links:32768
uid:0(root)
gid:14680064(?)
size:32768 bytes
block size:140720448604152
blocks:798863917062
last access:1970-01-01 05:30:00
last modification:1970-01-01 05:30:00
last status change:1970-01-01 05:30:00
============================================================================
*/

