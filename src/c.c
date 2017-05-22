#include<stdio.h>

int main()
{
int a = 90;
printf("%c", *((char*)(&a)+2));
}
