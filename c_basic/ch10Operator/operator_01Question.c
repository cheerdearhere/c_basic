#include <stdio.h>
/*
����1 
����ڷκ��� �� ������ �Է¹޾� ����� ����ϴ� ����. 
��� �Լ�: scanf_s, printf
��հ� ��½� �ݵ�� �Ҽ��� ��° �ڸ������� ǥ��
�ܼ� ����
	�� ������ �Է��ϼ��� : 10 20
	AVG: 15.00
*/
int main(void) {
	int a=0, b=0;
	printf("�� ������ �Է��ϼ��� : ");
	scanf_s("%d%d", &a, &b);
	printf("AVG: %.2f", (double)(a + b)/2);
	return 0;
}