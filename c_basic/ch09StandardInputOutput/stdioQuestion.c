#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int userAge = 0;
	char userName[30] = { 0 };

	printf("���̸� �Է��ϼ���: ");
	scanf_s("%d%*c", &userAge);

	printf("�̸��� �Է��ϼ���: ");
	gets_s(userName, sizeof(userName));

	printf("����� ���̴� %d���̰� �̸��� '%s' �Դϴ�.\n", userAge, userName);
}

/*
����ڷκ��� �̸��� ���̸� Ű����� �Է¹޾� ����ϴ� ���α׷�
�̸��� gets_s, ���̴� scanf_s �Լ��� �Է¹ް�
printf �Լ��� ���
���� ����
	���̸� �Է��ϼ���: 20
	�̸��� �Է��ϼ���: ö��

	����� ���̴� 20���̰� �̸��� 'ö��' �Դϴ�.
*/