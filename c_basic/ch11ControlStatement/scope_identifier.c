#include<stdio.h>
int main(void) 
{
	int x = 1;//1
	printf("%d\n", x); //1 stack frame
	if (x > 0) {
		int x = 2;//2
		printf("%d\n", x); //2 stack frame
		if (x > 1) {
			int x = 3;//3 
			printf("%d\n", x); //3 stack frame
		}
	}
	//	printf("%d",b); // b�� ���� �Ұ�
	printf("%d\n", x);//2,3�� scope�� ��� stack frame�� ����� �Բ� �Ҹ�� 
	// 1 stack frame ȣ��

	int nInput = 0; //1��
	scanf_s("%d", &nInput);
	printf("1: before: %d\n", nInput);

	if (nInput > 0) {
		printf("2: before: %d\n", nInput);
		int nInput = 100; //2��
		printf("2: after: %d\n", nInput);
	}

	printf("1: after: %d\n", nInput);

	return 0;
}