#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <sched.h>


int globalData = 0;
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *updateFootEventGen(void *vargp)
{
	for(int i = 0; i < 10; i++){
    sleep(0.2);
    sched_yield();
    printf("Printing GeeksQuiz from Thread \n");
    printf("GlobalData = %d\n\r" , globalData);
    fflush( stdout );
	}
	pthread_exit(NULL);
    return NULL;
}

void *updateAllFootStateParametersthread(void *vargp){
	for(int i = 0; i < 20; i++){
	sleep(0.5);
	sched_yield();
	globalData +=1;
	}
	pthread_exit(NULL);
}

void test_thread(int argc, char *argv[])
{
    pthread_t thread_id;
    pthread_t thread_id2;
    printf("Before Threads\n");
    int rc;
    rc = pthread_create(&thread_id, NULL, updateFootEventGen, (void *) 1);
    if(rc){printf("ERROR; return code from pthread_create() is %d\n", rc);}
    rc = pthread_create(&thread_id2, NULL, updateAllFootStateParametersthread,(void *) 2);
    if(rc){printf("ERROR; return code from pthread_create() is %d\n", rc);}
    sleep(10);
    printf("After Threads\n");
}
