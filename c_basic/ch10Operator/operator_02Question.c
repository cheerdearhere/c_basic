#include <stdio.h>
/*
����2
����ڷ�	���� ������ ��(second)�� �Է¹޾� '��:��:��' �������� ���
��, ��, �� ������ ��� ���ڸ� ������ ǥ���ϰ� 
�� �ڸ� ������ ��� �տ� 0�� �ٿ� ���
�ܼ� ����
	�ʸ� �Է��ϼ���: 4000
	4000�ʴ� 1�ð� 06�� 40�� �Դϴ�. 
*/
int main(void) {
	int inputSec = 0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;

	printf("�ʸ� �Է��ϼ���: ");
	scanf_s("%d",&inputSec);
	
	minutes = inputSec / 60;
	seconds = inputSec % 60;

	hours = minutes / 60;
	minutes = minutes % 60;

	printf("%d�ʴ� %d�ð� %02d�� %02d�� �Դϴ�\n", inputSec, hours, minutes, seconds);
/* 
�����Ʈ	

*/
	return 0;
}