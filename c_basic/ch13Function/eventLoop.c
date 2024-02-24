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
		printf("나이를 입력해주세요 : ");
		scanf_s("%d%*c", &nAge);
		if (nAge < 0) {
			printf("나이는 0 이상입니다. \n");
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
		1 //10 이상
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
			printf("요금은 %d원 입니다\n", GetFee(nAge));
			continue;
		case 2:
			puts("Search: 미구현 항목\n");
			continue;
		case 3:
			puts("Print: 미구현 항목");
			continue;
		case 4:
			puts("Remove: 미구현 항목");
			continue;
		default:
			puts("잘못된 입력입니다.");
			continue;
		}
	}
	puts("시스템을 종료합니다");

	return 0;
}
