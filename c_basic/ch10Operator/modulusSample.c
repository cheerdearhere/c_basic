#include <stdio.h>
int main(void) {
	int x = 0;
	scanf_s("%d", &x);//&(�ּ� ������): write ������ �ִ� ������ �ǿ����ڷ� ���� 
	printf("���� ��: %d \n", x / 3);
	printf("�Ǽ� ��: %.2f \n", (double)x / 3);// ����ȯ �ؼ� ���
	printf("������: %d \n", x % 3);
	return 0;
}