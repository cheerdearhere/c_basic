#include <stdio.h>
int main(void) {

	int nAge = 0;

	printf("���̸� �Է����ּ���: ");
	scanf_s("%d", &nAge);

	if (nAge >= 20) printf("����� ���̴� %d�� �Դϴ�.\n", nAge);

	puts("End");

	return 0;
}