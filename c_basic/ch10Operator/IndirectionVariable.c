#include <stdio.h>
int main(void) {
	int x = 0, nInput = 0;
	scanf_s("%d", &nInput);

	x = nInput;//���Կ���
	//����� �Է��� �ȵ�
	//3 = 4;
	printf("%d\n", x);
	//�迭�� '�ּһ��'�� ������ �ƴϴ�
	char szBuffer[32] = { 0 };
	//szBuffer = 3;
	szBuffer[0] = 3;
	return 0;
}