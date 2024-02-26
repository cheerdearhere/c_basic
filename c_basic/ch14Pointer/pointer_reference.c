#include <stdio.h>
int main(void){
	int x = 10;
	int* pnData = &x; // 간접 참조
	printf("x: %d\n", x);
	*pnData = 20; // 직접 참조
	printf("x: %d\n", x);

	return 0;
}