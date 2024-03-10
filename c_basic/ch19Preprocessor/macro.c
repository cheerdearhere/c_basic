#include <stdio.h>

int AddFnc(int a, int b) {
	return a + b;
}

#define ADD_MACRO(a,b)(a+b)

int main(void) {

	printf("fnc: %d\n", AddFnc(3, 4));
	printf("macro: %d\n", ADD_MACRO(3, 4));

	return 0;
}