#include <stdio.h>
/*
����1 
����ڷκ��� �Է� ���� ���� �� ���� ū ���� ����ϴ� ���α׷��� �ۼ�. 
���ѻ���
	������ ��ȣ�� �ִ� 32��Ʈ ������ ����
	scanf_s�Լ��� �ѹ��� �� ���� �Է�
	���������� �ִ��� ��� �����ϴ� ������ �ۼ�
	if�� ���
��� ����
	10
	20
	30
	MAX : 30
*/
int main(void) {
	int nInput = 0, max = 0;

	scanf_s("%d", &nInput);
	max = nInput;
	scanf_s("%d", &nInput);
	if (max < nInput) max = nInput;
	scanf_s("%d", &nInput);
	if (max < nInput) max = nInput;

	printf("MAX : %d\n", max);

	return 0;
}/*
 �����Ʈ:
 ��: 
 */