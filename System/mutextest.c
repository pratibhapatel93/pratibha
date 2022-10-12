#include "worker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//The volatile qualifier informs the compiler that the value of variable
//can change in an unexpected manner between different statements and
//as such it must not optimize its access. It is commonly used for a
//a variable which is accessed concurrently
volatile int collection = 0;

void* ProcessDonation(void* arg)
{
	//value of static local variable is shared across function calls
	static pthread_mutex_t monitor = PTHREAD_MUTEX_INITIALIZER;
	int notes = rand() % 5 + 1;

	printf("Agent<%lx> received %d hundred from %s\n", pthread_self(), notes, (char*)arg);
	pthread_mutex_lock(&monitor);
	collection = DoWork(notes, collection);:
	pthread_mutex_unlock(&monitor);

	return NULL;
}

int main(void)
{
	char* donors[] = {"Ashish", "Ketan", "Pooja", "Nisha"};
	pthread_t children[4];
	int i;
	
	srand(getpid());
	for(i = 0; i < 4; ++i)
	{
		pthread_create(&children[i], NULL, ProcessDonation, donors[i]);
	}

	for(i = 0; i < 4; ++i)
		pthread_join(children[i], NULL);

	printf("Total amount collected = %d\n", 100 * collection);
	
}

