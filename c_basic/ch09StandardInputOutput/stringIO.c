#include <stdio.h>

int main(void) {
	char szName[32] = { 0 };

	printf("�̸��� �Է��ϼ��� : ");
	gets(szName);
	// gets()�� ���� ���� ������ ���� gets_s(char[] buffer, size) ����
	printf("����� �̸��� ");
	puts(szName);
	printf("�Դϴ�.");

	return 0;
}