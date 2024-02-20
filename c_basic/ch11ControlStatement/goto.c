#include <stdio.h>
int main(void){
	int nInput;
INPUT:
	printf("Input Number(0~10) : ");;
	scanf_s("%d", &nInput);

	//조건에 맞지 않으면 사용자 입력을 재요청해 버림
	if (nInput < 0 || nInput > 10)
		goto INPUT;

	puts("END");
}