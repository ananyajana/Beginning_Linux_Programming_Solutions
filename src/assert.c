#include <stdio.h>
#include <math.h>
#include <assert.h>


double my_sqrt(double x)
{
	assert(x >= 0.0);
	return sqrt(x);
}
		
int main()
{
	printf("sqrt of  +2.0 = %g\n", my_sqrt(2.0));
	printf("sqrt of  -2.0 = %g\n", my_sqrt(-2.0));

	return 0;
}

