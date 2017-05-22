#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	char* message;
	int n;
	int exit_code;

	printf("Fork process starts:\n");
	pid = fork();

	switch(pid){
		case -1:
			perror("fork failed\n");
			exit(1);
	 	case 0:
			message = "I am child\n";
			n = 3;
			exit_code = 37;
			break;
		default:
			message = "I am parent\n";
			n = 5;
			exit_code = 0;
	}

	for(; n > 0; --n){
		puts(message);
		sleep(2);
	}

	if(pid){
		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);
		printf("child with PID %d has finished.\n", child_pid);
		
		if(WIFEXITED(stat_val))
			printf("The child has exited with code %d.\n", WEXITSTATUS(stat_val));
		else
			printf("Child exited abnormally.\n");

	}
	exit(0);
}

