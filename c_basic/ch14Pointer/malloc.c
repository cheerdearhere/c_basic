#include <stdio.h>
int main(void) {
	int* pList = NULL;

	pList = (int*)malloc(sizeof(int) * 3);
	//int 3�� ũ���� �ڸ� 3���� �غ��ض�
	// ���߽������� ��. runtime���� �ľ�
	pList[0] = 10;
	pList[1] = 20;
	pList[2] = 30;

	for (int i = 0; i < 3; i++)
		printf("%d %d\n", i, pList[i]);
	free(pList);// �޸� ��ȯ

	return 0;
}