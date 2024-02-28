#include <stdio.h>

int Add(int* a, int* b) {
	return *a + *b;
}
int main(int argc, char* argv[]) {

	int x = 3, y = 4;
	printf("%d\n", Add(&x, &y));

	return 0;
}