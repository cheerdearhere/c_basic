#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int x = 0;
	char ch = 0;

	printf("������ ���ڸ� �Է����ּ���: ");
	scanf_s("%d%c", &x, &ch, sizeof(ch));
	printf("�Է��� ���� %d�̰� ���ڴ� %c�Դϴ� \n", x, ch);

	return 0;
}