#include "worker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void HandleJob(int id)
{
	printf("Thread<%lx> has accepted job<%d>\n", pthread_self(), id);
	DoWork(10 * id, 0);
	printf("Thread<%lx> has finished job<%d>\n", pthread_self(), id);
}

void* ChildRoutine(void* arg)
{
	HandleJob(3);
	return NULL;
}

int main(void)
{
	pthread_t child;

	//creating a new thread to concurrently execute ChildRoutine 
	pthread_create(&child, NULL, ChildRoutine, NULL); 

	HandleJob(2);

	pthread_join(child, NULL); //wait for child thread to exit
}

