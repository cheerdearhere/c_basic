#include <stdio.h>
#include <stdlib.h>
/*
����1: ������
1~9���� ������ǥ ���
��¿���
	###1�� ����
	1 X 1 = 1
	...
	### 1�� ��
*/
int main(void) {
	for (int i = 1; i <= 9; i++) {
		printf("%d�� ����\n", i);
		for (int j = 1; j <= 9; j++) {
			printf("%d X %d = %d\n", i, j, i * j);
		}
		printf("%d�� ��\n", i);
	}
	return 0;
}
/*
�����Ʈ:
��: 
*/