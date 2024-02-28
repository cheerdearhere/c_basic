#include <stdio.h>

int Add(int a, int b) {
	int c = 0;
	c = a + b;
	return c;
}
int main(int argc, char* argv[]) {
	int a = 7;
	int res = 0;
	res = Add(3, 4);
	printf("%d\n", res);
	return 0;
}
