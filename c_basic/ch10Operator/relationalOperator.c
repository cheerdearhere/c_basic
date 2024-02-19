#include <stdio.h>
#include <stdlib.h>
int main(void) {
	//integer
	int x = 5, y = 10;
	printf("x == y : %d\n", x == y);
	printf("x != y : %d\n", x != y);
	printf("x > 5  : %d\n", x > 5);
	printf("y < 5  : %d\n", y < 5);
	printf("y >= 10  : %d\n", y >= 10);

	printf("y <= x + 5 : %d\n", y <= x + 5);
	
	//float, double
	printf("299.99999F: %d\n", 300 == 299.99999F);
	printf("299.99999: %d\n", 300 == 299.99999);
	printf("299.9999F: %d\n", 300 == 299.9999F);
	printf("300.00001F: %d\n", 300 == 300.00001F);

	return 0;
}