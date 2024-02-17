#include <stdio.h>
int main(void) {
	char ch = 'A';

	printf("%c\n", ch);

	printf("%c\n", ch + 1);
	printf("%d\n", ch + 1);
	printf("%c\n", 'A' + 2);

	printf("%d\n", 5.0 + 2);
	printf("%f\n", 5.0 + 2);

	int x = 5;
	printf("%d\n", 5 / 2);				// int/int -> int
	printf("%f\n", 5.0 / 2);			// double/int -> double
	printf("%f\n", 5 / 2.0);			// int/double -> double
	printf("%f\n", (double)5 / 2);		// (double)int/int -> double
	printf("%f\n", (double)x / 2);		// (double)int/int -> double
	printf("%f\n", 5 / (double)2);		// int/(double)int -> double
	printf("%f\n", (double)(x / 2));	// (double)(int/int) -> double
	
	unsigned int data = 257;
	unsigned char ch;

	ch = data;

	printf("%d\n", ch);

	return 0;
}