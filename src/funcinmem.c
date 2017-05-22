#include <stdio.h>
#include <malloc.h>
#include <string.h>

int iGlobalInit = 1;
int iGlobalUninit;
char* szGlobalP;

void function(char* cParameter, int iParameter)
{
	int iLocalInit = 1;
	int iLocalUninit;
	char szHelloString[12] = "Hello World!";
	char* szLocalP;
	
	iParameter = 5;
	
	iLocalUninit = iParameter;
	iGlobalUninit = iLocalUninit + 1;
	
	szGlobalP = (char*)malloc(12 * sizeof(char));
	strncpy(szGlobalP, "Hello World!", 12);
	
	szLocalP = (char*)malloc(12 * sizeof(char));
	strncpy(szLocalP, "Hello World!", 12);
	
	return;
}

int main(int argc, char** argv)
{
	int iMainLocalInit = 2;
	
	function("test", 0);
	
	iMainLocalInit += 1;
	iGlobalInit += iMainLocalInit;
	
	printf("iMainLocalInit = %d\n", iMainLocalInit);
}
