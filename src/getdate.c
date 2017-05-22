#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[])
{
	char* host;
	int sockfd;
	int len, result;
	struct sockaddr_in address;
	struct hostent* hostinfo;
	struct servent* servinfo;
	char buffer[128];

	if(argc == 1)
		host = "localhost";
	else
		host = argv[1];

	hostinfo = gethostbyname(host);
	if(!hostinfo){
		fprintf(stderr, "No host: %s\n", host);
		exit(1);
	}
	servinfo = getservbyname("daytime", "tcp");
	if(!servinfo){
		fprintf(stderr, "no daytime service");
		exit(1);
	}
	printf("daytime port is: %d\n", ntohs(servinfo->s_port));

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = servinfo->s_port;
	address.sin_addr = *(struct in_addr*)*hostinfo->h_addr_list;
	len = sizeof(address);

	result = connect(sockfd, (struct sockaddr*)&address, len);
	if(result == -1){
		perror("Oops!getdate:");
		exit(1);
	}
	
	result = read(sockfd, buffer, sizeof(buffer));
	buffer[result] = '\0';
	printf("Read %d bytes: %s\n", result, buffer);
	
	close(sockfd);
	exit(0);
}
