#include <stdio.h>
int main(void) {
	int x = 0;
	scanf_s("%d", &x);//&(주소 연산자): write 권한이 있는 변수를 피연산자로 받음 
	printf("정수 몫: %d \n", x / 3);
	printf("실수 몫: %.2f \n", (double)x / 3);// 형변환 해서 사용
	printf("나머지: %d \n", x % 3);
	return 0;
}