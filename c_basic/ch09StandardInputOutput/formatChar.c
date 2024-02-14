#include <stdio.h>
int main(void) {
	int x = 10;

	// 문자 상수를 화면에 출력
	putchar('B');
	// '\n'은 개행 문자이므로 알파벳 문자가 화면에 보이는 것은 아니다
	putchar('\n');
	printf("%c\n", 'A');
	// '%d', '%c'는 형식 문자에 맞춰 변수 x에 담긴 정보를 출력한다
			// printf(format, variable)
	printf("x는 %d 입니다.", x);

	return 0;
}