#include <stdio.h>
int main(void) {
	char ch = 0;
	while (1) {
		ch = getchar();
		if (ch == 'x')
			continue; //���⼭ �ش� ȸ�� �������� �����⶧����
		//����ȸ����
		putchar(ch); //�� �κ��� �������� ����
	}
	puts("END");
	return 0;
}