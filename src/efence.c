#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* pointer = (char*) malloc( 1024 );
	pointer[0] = 0;

	pointer[1024] = 0;
	exit(0);
}
