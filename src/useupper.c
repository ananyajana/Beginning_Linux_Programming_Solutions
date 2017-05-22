#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	
	char* filename;

	if(argc != 2){
		fprintf(stderr, "Usage: useupper.\n");
		exit(1);
	}

	filename = argv[1];

	if(!freopen(filename, "r", stdin)){
		fprintf(stderr, "could not redirect stdin from file %s", filename);
		exit(2);
	}

	execl("./upper", "upper", (char*)0);
	perror("Could not exec ./upper.\n");
	exit(3);
}
