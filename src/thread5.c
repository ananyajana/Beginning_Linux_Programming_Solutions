#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg);

char message[] = "Hello World";
int thread_finished = 0;

int main()
{
	int res;
	pthread_t a_thread;
	pthread_attr_t thread_attr;

	res = pthread_attr_init(&thread_attr);
	if(res){
		perror("Attribute creation failed.\n");
		exit(EXIT_FAILURE);
	}

	res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
	if(res){
		perror("Setting detached attribute failed.\n");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, &thread_attr, thread_function, (void*)message);
	if(res){
		perror("Thread creation failed.\n");
		exit(EXIT_FAILURE);
	}

	(void)pthread_attr_destroy(&thread_attr);

	while(!thread_finished){
		printf("Waiting for thread to say it's finished.\n");
		sleep(1);
	}

	printf("Other thread finished.Bye.\n");

	exit(EXIT_SUCCESS);
}

void* thread_function(void* arg)
{
	printf("Thread funciton is running.\n");
	sleep(4);
	printf("Second thread setting finished flag.\n");
	thread_finished = 1;
	pthread_exit(NULL);
}
