#include <stdio.h>

void Swap(int* pLeft, int* pRight) {
	int nTmp = *pLeft;
	*pLeft = *pRight;
	*pRight = nTmp;
}

int main(int argc, char* argv[]) {

	int x = 10, y = 20;
	printf("x=%d, y=%d\n", x, y);

	Swap(&x, &y);
	printf("x=%d, y=%d\n", x, y);

	return 0;
}
