#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//��ó����
#define MAX_LENGTH 32
#define CUTOFF 70

int main(int argc, char* argv[]) {

	const int nCUTOFF = 70;
	int nInput=0;
	printf("������ �Է��ϼ���: ");
	scanf_s("%d",&nInput);

	//if (nInput >= 70)
	if(nInput >= nCUTOFF)
		printf("�հ��Դϴ�\n");
	else
		printf("���հ��Դϴ�\n");

	return 0;
}