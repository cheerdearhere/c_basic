#include <stdio.h>
/*
����1 : �ִ� �����̹� 
����ڷκ��� �Է� ���� ���� �� ���� ū ���� ����ϴ� ���α׷��� �ۼ�
���ѻ���
	������ ��ȣ�� �ִ� 32��Ʈ ������ ���� 
	scanf_s() �Լ��� �ѹ��� �� ���� �Է�
	���������� �ʴ��� ��� �����ϴ� ����
��� ����
	10
	20
	30
	MAX : 30
*/
int main(void) {
	int userInput = 0, max = 0;

	scanf_s("%d", &userInput);
	max = userInput;
	scanf_s("%d", &userInput);
	max = max < userInput ? userInput : max;
	scanf_s("%d", &userInput);
	max = max < userInput ? userInput : max;

	printf("MAX : %d", max);
	return 0;
}
/*
�����Ʈ: 
��: 
	- ���������� �ſ� �߿��� ����. ������ �� ��������
*/