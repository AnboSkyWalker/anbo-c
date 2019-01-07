#include <stdio.h>

int main(int argc, char *argv[])
{
	float f1 = 3.1415e2;
	printf("f1=%f\n", f1);	
	char c1 = 128;
	printf("c1=%d %c\n", c1, c1)   ;

	int x = 13;
	int y = 4;
	int c = x % y;
	int d = x / y;
	printf("c=%d; d=%d\n", c, d);

	int a=10;
	int b=0;
	b =	10*4, a*5;
	printf("b=%d\n", b);
	printf("%d\n", (10*4, a*5));
	return 0;
}
