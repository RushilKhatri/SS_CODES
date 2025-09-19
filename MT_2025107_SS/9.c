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
printf("Last access: %s", ctime(&st.st_atime));
printf("Last modification: %s", ctime(&st.st_mtime));
printf("Last status change: %s", ctime(&st.st_ctime));
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
Last access: Thu Jan  1 05:30:00 1970
Last modification: Thu Jan  1 05:30:00 1970
Last status change: Thu Jan  1 05:30:00 1970
============================================================================
*/

