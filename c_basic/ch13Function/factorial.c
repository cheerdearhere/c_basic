#include <stdio.h>
//int g_input = 3; ���������� ���� �̸����� �ʱ�ȭ�ϸ� ����
//���������� �ܺ� ���Ͽ��� �������� ���(extern ������ �����ϳ� �Ǽ��� �� ������..)
extern int g_input;

int CalculateFactorial(int nParam) {
	int nResult = 1, i = 0;
	for (i = 1; i <= nParam; i++) {
		nResult *= i;
	}
	//��������
	printf("other(): g_input - %d\n", g_input);
	return nResult;
}
void GetFactorial(void) {
	int nResult = 0, nInput = 0;
	printf("����� ���� ����(1 ~ 10)�� �Է��ϼ���: ");
	scanf_s("%d", &nInput);
	if (nInput < 1 || nInput > 10) {
		printf("ERROR: 1~10 ������ ������ �Է��ؾ��մϴ�\n����� �Է�: %d\n",nInput);
	}
	else {
		nResult = CalculateFactorial(nInput);
		printf("%d! : %d\n", nInput, nResult);
	}
}
// ���� �������� ���� ����
//int main(void) {
//
//	GetFactorial();
//
//	return 0;
//}