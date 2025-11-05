/*
============================================================================
Name : 2.c
Author : Rushil Khatri
Description : a program to print the system resource limits. Use getrlimit system call
Date: 20th October 2025
============================================================================
*/
#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>
int main()
{
    struct rlimit lim;
    getrlimit(RLIMIT_NOFILE,&lim);
    printf("Maxopen filessoft : %ld Maxopen files hard:%ld\n",(long)lim.rlim_cur,(long)lim.rlim_max);
    getrlimit(RLIMIT_CPU,&lim);
    printf("R_LIMIT_CPU soft : %ld R_LIMIT_CPU  hard:%ld\n",(long)lim.rlim_cur,(long)lim.rlim_max);
    getrlimit(RLIMIT_FSIZE,&lim);
    printf("LIMIT_FSIZE soft : %ld LIMIT_FSIZE hard:%ld\n",(long)lim.rlim_cur,(long)lim.rlim_max);
    getrlimit(RLIMIT_STACK,&lim);
    printf("RLIMIT_STACK soft : %ld RLIMIT_STACK hard:%ld\n",(long)lim.rlim_cur,(long)lim.rlim_max);
    return 0;
}
/*
===============================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques2$ ./2
Maxopen filessoft : 1024 Maxopen files hard:1048576
R_LIMIT_CPU soft : -1 R_LIMIT_CPU  hard:-1
LIMIT_FSIZE soft : -1 LIMIT_FSIZE hard:-1
RLIMIT_STACK soft : 8388608 RLIMIT_STACK hard:-1
===============================================================================
*/

