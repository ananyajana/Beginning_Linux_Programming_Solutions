#include <stdio.h>
#define WORK_SIZE 2

char work_area[WORK_SIZE];

int main()
{
	printf("Enter 4 characters.\n");
	fgets(work_area, WORK_SIZE, stdin);
	printf("You have entered:\n");
	printf("%s\n", work_area);
}
