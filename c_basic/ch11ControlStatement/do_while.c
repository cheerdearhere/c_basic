#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(void) {

	char ch = 0;
	/*
	while ((ch = getchar()) != 'x') {
		putchar(ch);
	}
	*/
	do {
		ch = getchar();
		putchar(ch);
	}
	while (ch != 'x');
	puts("END");

	return 0;
}