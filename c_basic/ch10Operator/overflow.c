#include <stdio.h>
int main(void) {
	unsigned int overChar = 256;
	unsigned int maxChar = 255;
	unsigned char ch;

	ch = overChar;
	printf("%d\n", ch);

	ch = maxChar;
	printf("%d\n", ch);
	return 0;
}