#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void f(char* p, int x)
{
	printf("p is \"%s\" and x is %i.", p, x);
}

int main()
{
	char* hello = "Hello";
	char* world = "World!";
	
	printf("%s %s\n", hello, world);

	char* p = "foo";
	int x = 7;
	f(p, x);

	int i = 0; scanf("%i", i);
}