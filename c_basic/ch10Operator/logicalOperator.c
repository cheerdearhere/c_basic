#include <stdio.h>
int main(void){
	int nInput = 0, bResult = 0;
	
	scanf_s("%d", &nInput);
	bResult = nInput < 4 || nInput >= 60;
	printf("result : %d(1: True, 0: False)\n", bResult);
	bResult = !bResult;
	printf("result : %d(1: True, 0: False)\n", bResult);


	int nAge = 0, nHeight = 0;
	printf("���̸� �Է��ϼ���: ");
	scanf_s("%d", &nAge);
	printf("Ű�� �Է��ϼ���: ");
	scanf_s("%d", &nHeight);

	printf("��� : %d(1:�հ�, 0:���հ�)",
		nAge >= 20 && nAge <= 30 && nHeight >= 150
	);

	return 0;
}