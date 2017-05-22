#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void* thread_function(void* arg);

char message[] = "Hello World.";
int main()
{
	int res;
	pthread_t a_thread;
	void* thread_result;

	res = pthread_create(&a_thread, NULL, thread_function, (void*)message);
	if(res){
		perror("Thread creation failed.\n");
		exit(EXIT_FAILURE);
	}

	sleep(3);
	printf("Canceling thread.\n");
	res = pthread_cancel(a_thread);
	if(res){
		perror("Thread cancelation failed.\n");
		exit(EXIT_FAILURE);
	}

	printf("Waiting for thread to finish.\n");
	res = pthread_join(a_thread, &thread_result);
	if(res){
		   perror("Thread join failed.\n");
		   exit(EXIT_FAILURE);
	}
	printf("Thread joined. It returned %s.\n", (char*)thread_result);
	printf("Message is now: %s.\n", message);
	exit(EXIT_SUCCESS);
}

void* thread_function(void* arg)
{
	int i, res;

	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if(res){
		perror("Thread pthread_setcancelstate failed.\n");
		exit(EXIT_FAILURE);
	}

	res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	if(res){
		perror("Thread pthread_setcanceltype failed.\n");
		exit(EXIT_FAILURE);
	}

	printf("Thread function is running.\n");
	for(i = 0; i < 10; ++i){
		printf("Thread is still running (%d).\n", i);
		sleep(1);
	}

	pthread_exit(0);
}
