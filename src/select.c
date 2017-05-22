#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>

int main()
{
	char buffer[128];
	int result, nread;

	fd_set inputs, test_fds;
	struct timeval timeout;

	FD_ZERO(&inputs);
	FD_SET(0, &inputs);

	while(1){
		test_fds = inputs;
		timeout.tv_sec = 2;
		timeout.tv_usec = 500000;

		result = select(FD_SETSIZE, &test_fds, (fd_set*)NULL, (fd_set*)NULL, &timeout);
		switch(result){
			case 0:
				printf("Timeout.\n");
				break;
			case -1:
				perror("select");
				exit(1);
			default:
				if(FD_ISSET(0, &test_fds)){
					ioctl(0, FIONREAD, &nread);
					if(nread == 0){
						printf("Keyboard done.\n");
						exit(0);
					}

					nread = read(0, buffer, nread);
					buffer[nread] = 0;
					printf("Read %d from keyboard: %s\n", nread, buffer);
				}
				break;
		}
	}
}
		
/* FIONREAD: Get the number of bytes that are immediately available for reading
The third parameter to the ioctl subroutine for this command is a pointer to an 
integer variable where the byte count is to be returned. */
