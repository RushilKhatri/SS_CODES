/*
============================================================================
Name : 6.c
Author : Rushil Khatri
Description : a simple program to create three threads.
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
    printf("hello from thread %d having the ID:%lu\n",id,pthread_self());
    sleep(15);
    printf("Thread %d exits\n",id);
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
    for(int i=0;i<3;i++)
    {
        pthread_join(threads[i],NULL);
    }
    printf("ALL THREADS EXITS FROM THE MAIN THREAD");
    return 0;
}
/*
===================================================================================
SAMPLE OUTPUT:-
rushil@rushil-HP-Envy-x360-2-in-1-Laptop-15-fe0xxx:~/Desktop/HOL2/Ques6$ ./6
hello from thread 2 having the ID:128379414111936
hello from thread 1 having the ID:128379422504640
hello from thread 3 having the ID:128379405719232
Thread 2 exits
Thread 3 exits
Thread 1 exits
ALL THREADS EXITS FROM THE MAIN THREAD
====================================================================================
*/