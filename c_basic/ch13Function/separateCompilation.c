#include <stdio.h>
#include "func.h"
//���� ������: �ٸ� �ҽ����Ͽ��� ������
int CalculateFactorial(int);
// ����� �����ϴ� ���: void GetFactorial(void) ���� ���

//��������
int g_input = 10;
int main(void) {
	printf("from factorial.c: %d\n", CalculateFactorial(5));
	GetFactorial();

	//��������
	printf("main(): g_input - %d\n", g_input);
	return 0;
}