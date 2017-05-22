// Producer process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo2"
#define BUFFER_SIZE	PIPE_BUF
#define TEN_MEG		(1024 * 1024 * 10)

int main()
{
	int res;
	int pipe_fd;
	int open_mode = O_WRONLY;
	int i;
	int bytes_sent = 0;
	char buffer[BUFFER_SIZE + 1];

	if(access(FIFO_NAME, F_OK) == -1){
		res = mkfifo(FIFO_NAME, 0777);
		if(res){
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}

	printf("Process %d opening file O_WRONLY", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);
	printf("Process %d result %d\n", getpid(), pipe_fd);

	if(pipe_fd != -1){
		while(bytes_sent < TEN_MEG){
			res = write(pipe_fd, buffer, BUFFER_SIZE);
			if(res == -1){
				fprintf(stderr, "Could not write to fifo");
				exit(EXIT_FAILURE);
			}

			bytes_sent += res;

		}
		(void)close(pipe_fd);
	}
	else
		exit(EXIT_FAILURE);
	printf("Process %d finished.\n", getpid());
}
