#include <stdio.h>
#define a (x+1)

int x = 2;

void b ()
{
	x = a;
	printf("%d\n", x);
}

void c ()
{
	int x = 1;

	printf("%d\n", a);
}

int main(int argc, char const *argv[])
{

	b(); // will print 3
	c(); // will print 2

	return 0;
}
