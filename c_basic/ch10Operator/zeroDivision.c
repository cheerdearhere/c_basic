#include <stdio.h>
int main(void) {
	int nInput = 0;
	printf("정수를 입력하세요: ");
	scanf_s("%d", &nInput);

	printf("10 / %d = %d \n", nInput, 10 / nInput);
	printf("10.0 / %d = %.3f \n", nInput, 10.0 / nInput);
	return nInput;
}