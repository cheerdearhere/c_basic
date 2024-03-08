#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int nData; 
	const int a = 3, b = 4;
//	nData = 3 + 4;
	volatile int c = 5;
	nData = a + b + c;
	printf("%d\n", nData);

	return 0;
}