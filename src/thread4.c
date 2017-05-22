#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <string.h>

void* thread_function(void* arg);
pthread_mutex_t work_mutex;	/*protects both work aren and time to exit. */
#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main()
{
	int res;
	pthread_t a_thread;
	void* thread_result;

	res = pthread_mutex_init(&work_mutex, NULL);
	if(res){
		perror("Mutex initialization failed.\n");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if(res){
		perror("Thread creation failed.\n");
		exit(EXIT_FAILURE);
	}

	pthread_mutex_lock(&work_mutex);
	printf("Input some text. Enter 'end' to finish.\n");
	
	while(!time_to_exit){
		fgets(work_area, WORK_SIZE, stdin);
		pthread_mutex_unlock(&work_mutex);
		while(1){
			pthread_mutex_lock(&work_mutex);
			if(work_area[0] != '\0'){
				pthread_mutex_unlock(&work_mutex);
				sleep(1);
			}
			else
				break;
		}
	}

	pthread_mutex_unlock(&work_mutex);
	printf("\nWaiting for thread to finish. . .\n");

	res = pthread_join(a_thread, &thread_result);
        if(res){
		perror("Thread join failed.\n");
		exit(EXIT_FAILURE);
	}

	pthread_mutex_destroy(&work_mutex);
	exit(EXIT_SUCCESS);
}

void* thread_function(void* arg)
{
	sleep(1);
	pthread_mutex_lock(&work_mutex);
	while(strncmp(work_area, "end", 3) != 0){
		printf("You input %d charcters.\n", strlen(work_area) - 1);
		work_area[0] = '\0';
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
		pthread_mutex_lock(&work_mutex);
		while(work_area[0] != '\0'){
			pthread_mutex_unlock(&work_mutex);
			sleep(1);
			pthread_mutex_lock(&work_mutex);
		}
	}

	time_to_exit = 1;
	work_area[0] = '\0';
	pthread_mutex_unlock(&work_mutex);
	pthread_exit(0);
}
	
