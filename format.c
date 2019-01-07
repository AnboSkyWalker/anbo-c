#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int x;
	for (int i=0; i<100*100; i++) {
		printf("%3d %8s \r", i, "abcdefg");
		for (int j=0; j<1e5; j++) {
			x += j;
			if (i % 4000 == 0 && j % 55546 == 0) {
				printf("Found key: %s\n", "sjdfsjkf");
			}
		}
		//sleep(1);
	}		
	printf("x=%d\n", x);
	return 0;
}
