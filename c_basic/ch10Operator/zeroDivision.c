#include <stdio.h>
int main(void) {
	int nInput = 0;
	printf("������ �Է��ϼ���: ");
	scanf_s("%d", &nInput);

	printf("10 / %d = %d \n", nInput, 10 / nInput);
	printf("10.0 / %d = %.3f \n", nInput, 10.0 / nInput);
	return nInput;
}