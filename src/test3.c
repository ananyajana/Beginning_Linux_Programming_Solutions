#include <stdio.h>
#include <string.h>

int main()
{
	printf("The error code %d means %s\n", 44, strerror(44));
}
