#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char name[32] = { 0 };
	int nAge = 0;

	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d%*c", &nAge);

	printf("�̸��� �Է��ϼ���: ");
	gets_s(name, sizeof(name));

	printf("����: %d��, �̸�: %s", nAge, name);

	return 0;
}