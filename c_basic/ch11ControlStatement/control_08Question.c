#include <stdio.h>
#include <stdlib.h>
/*
����: * ��� ����
�Ʒ� ��ó�� �ﰢ���� *�� ����ϴ� ���α׷��� �ۼ�
�� �� �̵ �ﰢ�� ���
���ѻ���
	for�� ���
	*�� ���� ������ tab���� ����
��¿���
					*
				*	*
			*	*	*
		*	*	*	*
	*	*	*	*	*
					*
				*	*	*
			*	*	*	*	*
		*	*	*	*	*	*	*
	*	*	*	*	*	*	*	*	*
*/
int main(void) {
	// �� ����
	for (int i = 5; i >= 1; i--) {
		for (int j = 1; j <= 5; j++) {
			if (i > j)
				printf("	");
			else
				printf("*	");
		}
		printf("\n");
	}
	// �̵
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 + i; j++) {
			if (j >= 4 - i)
				printf("*	");
			else
				printf("	");
		}
		printf("\n");
	}
	return 0;
}
/*
�����Ʈ:
��:
	- ��Ģ�� ã������ ��� ���� �����غ���
		row		*��ġ
		0	+	4	= 4
		1	+	3
		2	+	2
		3	+	1
		4	+	0
	- ��Ģ�� ã�Ҵٸ� ���ǹ����� �����ϰ� �б�
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if(j >= 4 - i)
					printf("*	");
				else
					printf("	");
			}
			printf("\n");
		}
	- ���� ������ �����ϸ� ���� ���� ����
*/