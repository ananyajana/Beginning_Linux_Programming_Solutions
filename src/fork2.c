#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	char* message;
	int n;

	printf("Fork process starts:\n");
	pid = fork();

	switch(pid){
		case -1:
			perror("fork failed\n");
			exit(1);
	 	case 0:
			message = "I am child\n";
			n = 5;
			break;
		default:
			message = "I am parent\n";
			n = 5;
	}

	for(; n > 0; --n){
		puts(message);
		sleep(6);
	}
}
