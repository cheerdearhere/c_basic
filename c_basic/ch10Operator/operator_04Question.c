#include <stdio.h>
/*
����ڷκ��� �� ������ �Է¹޾� ������ ���
����� �Է��� ����Ǵ� ���� �ϳ��� ���� �����ϴ� ���� �ϳ��� ����� ����
��� ���� 
	1
	2
	3
	total: 6
*/
int main(void) {
	int saveNum = 0, inputNum = 0;

	scanf_s("%d", &inputNum);
	saveNum += inputNum;
	scanf_s("%d", &inputNum);
	saveNum += inputNum;
	scanf_s("%d", &inputNum);
	saveNum += inputNum;
	
	printf("Total: %d\n", saveNum);
	return 0;
/*
�����Ʈ: 
��: 
	- �������� �� �� �������̰� ª�� ����: 
		saveNum -> total
		inputNum -> input
	- ��ü�� �����⺸�� �׽�Ʈ �ڵ��:
		ó������ scanf_s�� ���⺸�� ����� ���
		input = 1;
	- ���������� �����ϰ� �ʱ�ȭ���� ������ ������ ������ �� ����. 
*/
}