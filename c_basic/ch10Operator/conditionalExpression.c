#include <stdio.h>
#include <stdlib.h>
int main(void) {

	int nInput = 0, nSelect = 0;

	scanf_s("%d", &nInput);
	nSelect = nInput <= 10 ? 10 : 20;
	printf("res : %d\n", nSelect);

	printf("������ ���� ��\n");

	return 0;
}