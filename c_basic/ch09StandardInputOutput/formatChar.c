#include <stdio.h>
int main(void) {
	int x = 10;

	// ���� ����� ȭ�鿡 ���
	putchar('B');
	// '\n'�� ���� �����̹Ƿ� ���ĺ� ���ڰ� ȭ�鿡 ���̴� ���� �ƴϴ�
	putchar('\n');
	printf("%c\n", 'A');
	// '%d', '%c'�� ���� ���ڿ� ���� ���� x�� ��� ������ ����Ѵ�
			// printf(format, variable)
	printf("x�� %d �Դϴ�.", x);

	return 0;
}