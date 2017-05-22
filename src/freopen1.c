#include <stdio.h>
#include <stdlib.h>


int main()
{
	freopen("a.txt", "w", stdout);
	printf("This should be written in the file.\n");
	fclose(stdout);
	exit(0);
}
