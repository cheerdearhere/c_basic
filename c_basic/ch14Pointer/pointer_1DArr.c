#include <stdio.h>
int main(void) {

	int aList[5] = { 0 };
	int* pnData = aList; // idx 0의 주소
	//int *pnData = &aList[0];

	printf("aList[0] : %d\n", aList[0]);
	*pnData = 20;
	printf("aList[0] : %d\n", aList[0]);// 같은 주소를 사용
	printf("pnData[0] : %d\n", pnData[0]);
	return 0;
}