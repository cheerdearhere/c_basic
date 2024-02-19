#include <stdio.h>
int main(void) {
	int intVar = 5;
	int ointVar = 0x1234567;
	char charVar = 'A';
	float floatVar = 123.45F;
	double doubleVar = 123.45;

	printf("%d: %d, 0x%08x: %d, int: %d\n", intVar, sizeof(intVar), ointVar, sizeof(ointVar), sizeof(int));
	printf("%c: %d, char: %d\n", charVar, sizeof(charVar), sizeof(char));
	printf("%fF: %d, %f: %d\n", floatVar, sizeof(floatVar), doubleVar, sizeof(doubleVar));

	printf("+10: %d, ++: %d\n", sizeof(ointVar + 10), sizeof(++ointVar));
	printf("%d\n", sizeof(ointVar));

	int aList[16];
	printf("%d\n", sizeof(aList));
	printf("%d\n", _countof(aList));
	printf("%lld\n", sizeof(aList));
	printf("%lld\n", _countof(aList));
	return 0;
}