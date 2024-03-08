#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//전처리기
#define MAX_LENGTH 32
#define CUTOFF 70

int main(int argc, char* argv[]) {

	const int nCUTOFF = 70;
	int nInput=0;
	printf("점수를 입력하세요: ");
	scanf_s("%d",&nInput);

	//if (nInput >= 70)
	if(nInput >= nCUTOFF)
		printf("합격입니다\n");
	else
		printf("불합격입니다\n");

	return 0;
}