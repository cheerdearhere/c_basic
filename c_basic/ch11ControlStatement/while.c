#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(void) {

	char ch = 0;
	while ((ch = getchar()) != 'x') {
		putchar(ch);
	}

	int nInput = -1;
	while (nInput < 0 || nInput >10) {
		printf("Input numper: ");
		scanf_s("%d", &nInput);
	}
	puts("END");

	return 0;
}