#include <stdio.h>
int main(void) {
	int nInput = 0, nSelect = 0;
	scanf_s("%d", &nInput);

	if (nInput <= 10)
		nSelect = 10;
	else
		nSelect = 20;
	nSelect = nInput <= 10 ? 10 : 20;//3�� �����ڷε� ����
	printf("select %d\n", nSelect);
	return 0;
}