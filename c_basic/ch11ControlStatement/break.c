#include <stdio.h>

int main(void) {
	char ch = 0;
	while (1) {
		ch = getchar();
		if (ch == 'x')
			break; //���⼭ �������� �����⶧����
		putchar(ch); //�� �κ��� �������� ����
	}
	puts("END");
	return 0;
}