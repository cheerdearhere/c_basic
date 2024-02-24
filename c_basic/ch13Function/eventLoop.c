#include <stdio.h>
#include <stdlib.h>

int PrintMenu(void) {
	int nSelect = 0;

	system("cls");
	printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]END\n: ");
	scanf_s("%d%*c", &nSelect);
	return nSelect;
}
int GetAge(void) {
	int nAge = 0;
	while (1) {
		printf("���̸� �Է����ּ��� : ");
		scanf_s("%d%*c", &nAge);
		if (nAge < 0) {
			printf("���̴� 0 �̻��Դϴ�. \n");
			continue;
		}
		else
			break;
	}
	return nAge;
}
int GetFee(int nAge) {
	int nFee = 1000;
	double dRate[11] = {
		0, // 0
		0.3, 0.5, //1, 2
		0.6, 0.65, //3, 4
		0.7, 0.75, //5, 6
		0.8, 0.85, //7, 8
		0.95, // 9
		1 //10 �̻�
	};
	if (nAge >= 10) nAge = 10;

	return (int)(nFee * dRate[nAge]);
}
int main(void) {

	int nMenu = 0, nAge = 0;
	while ((nMenu = PrintMenu()) != 0) {
		switch (nMenu) {
		case 1:
			nAge = GetAge();
			printf("����� %d�� �Դϴ�\n", GetFee(nAge));
			continue;
		case 2:
			puts("Search: �̱��� �׸�\n");
			continue;
		case 3:
			puts("Print: �̱��� �׸�");
			continue;
		case 4:
			puts("Remove: �̱��� �׸�");
			continue;
		default:
			puts("�߸��� �Է��Դϴ�.");
			continue;
		}
	}
	puts("�ý����� �����մϴ�");

	return 0;
}
