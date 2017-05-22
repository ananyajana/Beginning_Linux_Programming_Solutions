#include <stdio.h>

int main()
{
	printf("Hi there\n");
	#ifdef DEBUG
	printf("Compiled at:" __DATE__ "time:" __TIME__"\n");
	printf("This is line no.: %d of file %s\n", __LINE__, __FILE__);
	#endif
}
