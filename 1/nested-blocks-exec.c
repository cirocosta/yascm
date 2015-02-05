#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a = 1;
	int b = 1;

	{
		int b = 2;
		{
			int a = 3;
			printf("%d, %d\n", a, b);
		}
		{
			int b = 4;
			printf("%d, %d\n", a, b);
		}
		printf("%d, %d\n", a, b);
	}
	printf("%d, %d\n", a, b);


	return 0;
}
