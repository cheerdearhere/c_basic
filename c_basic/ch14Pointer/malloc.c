#include <stdio.h>
int main(void) {
	int* pList = NULL;

	pList = (int*)malloc(sizeof(int) * 3);
	//int 3개 크기의 자리 3개를 준비해라
	// 개발시점에는 모름. runtime에서 파악
	pList[0] = 10;
	pList[1] = 20;
	pList[2] = 30;

	for (int i = 0; i < 3; i++)
		printf("%d %d\n", i, pList[i]);
	free(pList);// 메모리 반환

	return 0;
}