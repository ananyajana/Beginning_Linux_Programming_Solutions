#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("Running ls with execlp\n");
	execlp("ls", "ls", "-a", (char*)0);
	printf("Done.\n");
	exit(0);
}
