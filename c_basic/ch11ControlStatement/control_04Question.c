#include <stdio.h>
#include <stdlib.h>
/*
����: 
����ڷκ��� ������ �Է¹޾� �� ����ŭ '*'�� ����ϴ� ���α׷��� �ۼ�. 
����� �Է��� ������ �Ѿ�� ������ ����
���ѻ���
	1~9 ������ ������ �Է�
	*�� �� �࿡ �̾ ����ϰ� ��ü ����� ������ ����
��¿���
	3
	* * *
	5
	* * * * *
*/
int main(void) {
	int i = 0;
	while (i < 1 || i > 9) {
		printf("1~9������ ������ �Է��ϼ���.\n");
		scanf_s("%d", &i);
	}
	while (i > 0) {
		putchar('*');
		--i;
		if (i == 0) {
			putchar("\n");
			break;
		}
	}
	puts("END");
	return 0;
}
/*
�����Ʈ:
��: 
- input�� i�� ���� �ִ� �͵� ���
	while(i<input){
		putchar('*');
		++i;
	}
	putchar("\n");
- printf()�� ���Ĺ��� ����ϸ� ���� ����
	printf("*\t");
*/