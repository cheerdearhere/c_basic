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

	printf("%d�ʴ� %02d�ð� %02d�� %02d�� �Դϴ�\n", inputSec, hours, minutes, seconds);
/* 
�����Ʈ	
	�ð��� 0ǥ�� ����: %02d
��
	- �켱 �Է°� ����� üũ�ϰ� ������ �����ϸ� ���ϴ�
	- �Ź� �Է��ϱ⺸�� ���ð�(4000)�� �ʱ�ȭ���� ó���ϰ� ������ �����ϸ� �ð��� ���� �� �ִ�.
	- �� ������: ����� �ڵ�
		- ������ �ϳ��� �������ϸ� �����ϱ� ����
			hour = input / 3600;
			min = (input % 3600) / 60;
			sec = input % 60;
		- ���� ������ �ʿ��Ѱ� üũ
			printf("%d�ʴ� %02d�ð� %02d�� %02d�� �Դϴ�\n", 
				inputSec, 
				input / 3600, 
				(input % 3600) / 60, 
				input % 60
			);
		- ������ �ٲ�� ��� ������ ����� ó���� �Ǵ��� Ȯ��
			0, 59, 60, 3599, 3600...
*/
	return 0;
}