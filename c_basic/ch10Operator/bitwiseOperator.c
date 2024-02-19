#include <stdio.h>
int main(void) {

	//	int nData = 0x11223344;
	int nData = 0x12345678;

	printf("%08X\n", nData);
	printf("%d\n", nData);

	printf("%08X\n", nData & 0x00FFFF00); // AND
	printf("%08X\n", nData | 0x00FFFF00); // OR
	printf("%08X\n", nData ^ 0x00FFFF00); // XOR
	printf("%08X\n", ~nData); // NOT

	printf("%08X\n", nData >> 8); // Shift right
	printf("%08X\n", nData << 8); // Shift left

	printf("%d\n", nData);

	return 0;
}