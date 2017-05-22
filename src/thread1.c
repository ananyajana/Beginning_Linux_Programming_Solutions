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
	   char bye_message[] = "Thank you for CPU time.\n";
	   printf("Thread_function is running.\n");

	   sleep(3);
	   strcpy(message, "Bye!");
	   pthread_exit((void*)bye_message);
}