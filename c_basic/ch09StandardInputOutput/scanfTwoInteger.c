#include <stdio.h>
int main(void){
	int x = 0, y = 0;

	printf("�� ������ �Է��ϼ���");
	scanf_s("%d%d%*c", &x, &y);

	printf("�� ���� ���� %d �Դϴ�\n", x + y);
	
	return 0;
}