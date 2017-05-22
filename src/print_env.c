#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* user_name = getenv("USER");

	if(user_name)
		printf("%s\n", user_name);
	else
		exit(1);
}

