#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	freopen("a.txt", "r", stdin);
	execlp("cat", "cat", (char*)0);
	printf("hello.\n");
	exit(0);
}
