#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 8

int main()
{
	char s[SIZE];

	printf("Enter the string:\n");
	fgets(s, SIZE, stdin);
	printf("No. of chars %d\n", (int)strlen(s));
	exit(0);
}
