#include <stdio.h>
#define BASIC_DEBUG 1
#define EXTRA_DEBUG 2
#define SUPER_DEBUG 4

int main()
{
	int x = 5;
	printf("%d\n", 20);
	#if (BASIC_DEBUG & DEBUG)
	printf("the value of the variable x is = %d\n", x);
	#endif
	#if (SUPER_DEBUG & DEBUG)
	printf("x = %d\n", x);
	#endif
}
