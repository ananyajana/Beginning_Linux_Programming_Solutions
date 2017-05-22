#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define EXTRA_DEBUG 1

int run_now = 1;

void* thread_function(void* arg);

int main()
{
	   int res;
	   void* thread_result;
	   pthread_t a_thread;
	   int print_count1 = 0;

	   res = pthread_create(&a_thread, NULL,thread_function, (void*)NULL); 
	   if(res){
			 perror("thread creation failed.\n");
			 exit(EXIT_FAILURE);
	   }


 printf("Hello world.\n");


	   while(print_count1++ < 5){
         			    if(run_now == 1){
				    printf("1");
				    run_now = 2;
			 }
			 else
				    sleep(1);
	   }

	   res = pthread_join(a_thread, &thread_result);
	   if(res){
			 perror("Thread join failed.\n");
			 exit(EXIT_FAILURE);
	   }

	   printf("Finished.\n");
	   exit(0);
}

void* thread_function(void* arg)
{
	   int print_count2 = 0;

	   while(print_count2++ < 5){
			 if(run_now == 2){
				    printf("2");
				    run_now = 1;
			 }
			 else
				    sleep(1);
	   }

	   pthread_exit(NULL);
}
