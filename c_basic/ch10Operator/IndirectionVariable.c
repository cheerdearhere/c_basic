#include <stdio.h>
int main(void) {
	int x = 0, nInput = 0;
	scanf_s("%d", &nInput);

	x = nInput;//대입연산
	//상수에 입력이 안됨
	//3 = 4;
	printf("%d\n", x);
	//배열은 '주소상수'로 변수가 아니다
	char szBuffer[32] = { 0 };
	//szBuffer = 3;
	szBuffer[0] = 3;
	return 0;
}