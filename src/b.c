#include <stdio.h>
#include <string.h>
#include <malloc.h>

int i = 4;	// global initialized variable, .data section
int j;		// global uninitialized variable, .bss section
char* p;		// global uninitialized variable, .bss section

void f(char arg)
{
	int k = 1;	// local initialized data, stack
	int l;		// local uninitialized data, stack
	char m[12] = "Hello World!";	// local initialized, stack
	p = (char*)malloc( 12 * sizeof(char));
	strncpy(p, "Hello World!", 12);
}

int main()
{
	f(0);		// function call, new environment
}
	
