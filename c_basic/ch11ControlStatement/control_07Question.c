#include <stdio.h>
#include <stdlib.h>
/*
����: ���簢�� ���
5�� 5�� �簢���� *�� ����ϴ� ���α׷� �ۼ�
���� �밢������ ���� �ﰢ���� ���
���ѻ���
	for�� ���
��¿���
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	
	*	*	
	*	*	*	
	*	*	*	*
	*	*	*	*	*
*/
int main(void) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("* ");
		}
		printf("\n");
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
/*
�����Ʈ:
��: 
*/