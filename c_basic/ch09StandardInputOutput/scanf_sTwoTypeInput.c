#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int x = 0;
	char ch = 0;

	printf("정수와 문자를 입력해주세요: ");
	scanf_s("%d%c", &x, &ch, sizeof(ch));
	printf("입력한 수는 %d이고 문자는 %c입니다 \n", x, ch);

	return 0;
}