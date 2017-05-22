#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char *host, **names, **addrs;
	struct hostent *hostinfo;

	if(argc == 1){
		char myname[256];
		gethostname(myname, 255);
		host = myname;
	}
	else
		host = argv[1];
	
	hostinfo = gethostbyname(host);
	if(!hostinfo){
		fprintf(stderr, "Can't get for the host: %s\n", host);
		exit(EXIT_FAILURE);
	}

	printf("Results for host %s\n", host);
	printf("Name: %s\n", hostinfo->h_name);
	printf("Aliases:\n");
	names = hostinfo->h_aliases;
	
	while(*names){
		printf("%s\n", *names);
		names++;
	}
	printf("\n");

	if(hostinfo->h_addrtype != AF_INET){
		fprintf(stderr, "Not an IP host\n");
		exit(EXIT_FAILURE);
	}

	addrs = hostinfo->h_addr_list;
	while(*addrs){
		printf(" %s", inet_ntoa(*(struct in_addr*)*addrs));
		addrs++;
	}

	printf("\n");
	exit(EXIT_SUCCESS);
}
