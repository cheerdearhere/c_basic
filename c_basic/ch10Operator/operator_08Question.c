#include <stdio.h>
/*
����2: �ִ밪 ��ʸ�Ʈ
����ڷκ��� �Է¹��� ���� �� ���� ū ���� ����ϴ� ���α׷��� �ۼ�
���ѻ��� 
	������ ��ȣ�� �ִ� 32��Ʈ ������ ����
	scanf_s �Լ��� �� ���� ���
	�ִ밪�� printf() �Լ��� ���
��� ����
	10 20 30
	MAX : 30
*/
int main(void) {
	int a = 0, b = 0, c = 0;
	scanf_s("%d%d%d", &a, &b, &c);
	a = (a > b) ? ((a > c) ? a : c) : b;
	printf("MAX : %d", a);
	return 0;
}
/*
�����Ʈ: 
��: 
	- �б� ���� ������ �͵� ����
		int max = 0, a, b, c;
		...
		max = (a > b) ? a : b;
		max = (c > max) ? c : max;
		printf("MAX : %d", max);
*/