#include <stdio.h>
int main(void) {

	int nScore = 0;
	char chCredit = 'X';

	printf("점수를 입력하세요 : ");
	scanf_s("%d", &nScore);

	switch (nScore / 10) {
	case 10:
	case 9:
		chCredit = 'A';
		break;

	case 8:
		chCredit = 'B';
		break;
	case 7:
		chCredit = 'C';
		break;
	case 6:
		chCredit = 'D';
		break;
	default:
		chCredit = 'F';
		break;
	}

	printf("성적: %d, 학점: %c\n", nScore, chCredit);

	return 0;
}