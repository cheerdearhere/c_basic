#include <stdio.h>
#include <stdlib.h>
/*
����: 
����2: ���� ���
1~10���� ������ ����ϴ� ���α׷��� �ۼ�.
���ѻ���
	while���� for������ ���� �ۼ�
	�ݺ�ȸ���� 10ȸ
	������ �����ϴ� ������ Ȱ��
��¿���
	Total: 55
*/
int main(void) {
	int totalw = 0, i = 1;
	while (i <= 10) {
		totalw += i;
		i++;
	}
	printf("while total: %d\n", totalw);


	int totalf = 0;
	for (int j = 0; j < 10; j++) {
		totalf += (j + 1);
	}
	printf("for total: %d\n", totalf);
	return 0;
}
/*
�����Ʈ:
��: 
*/