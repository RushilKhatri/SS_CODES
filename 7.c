/*
============================================================================
Name : 7.c
Author : Rushil Khatri
Description :  a simple program to print the created thread ids.
Date: 20th October 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h> 
#include<unistd.h>
void * thread_func(void* arg)
{
    int id=*(int*)arg;
    printf("This is thread %d having the ID:%lu\n",id,pthread_self());
    return NULL;
}
int main()
{
    pthread_t threads[3];
    int ids[3]={1,2,3};
    for(int i=0;i<3;i++)
    {
        pthread_create(&threads[i],NULL, thread_func,&ids[i]);
    }
    for(int i = 0; i < 3; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques7$ ./7
This is thread 1 having the ID:139388384179904
This is thread 3 having the ID:139388367394496
This is thread 2 having the ID:139388375787200
====================================================================================
*/