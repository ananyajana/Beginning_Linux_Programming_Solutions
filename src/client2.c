#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/un.h>
#include <string.h>

int main()
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	char ch = 'A';

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = 9734;
	len = sizeof(address);

	result = connect(sockfd, (struct sockaddr*)&address, len);

	if(result == -1){
		perror("oops!client2");
		exit(EXIT_FAILURE);
	}

	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	printf("char from server: %c\n", ch);
	close(sockfd);
	exit(0);
}
