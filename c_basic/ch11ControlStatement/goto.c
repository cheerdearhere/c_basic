#include <stdio.h>
int main(void){
	int nInput;
INPUT:
	printf("Input Number(0~10) : ");;
	scanf_s("%d", &nInput);

	//���ǿ� ���� ������ ����� �Է��� ���û�� ����
	if (nInput < 0 || nInput > 10)
		goto INPUT;

	puts("END");
}