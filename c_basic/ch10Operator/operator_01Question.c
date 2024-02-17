#include <stdio.h>
/*
문제1 
사용자로부터 두 정수를 입력받아 평균을 출력하는 예제. 
사용 함수: scanf_s, printf
평균값 출력시 반드시 소수점 둘째 자리까지만 표시
콘솔 예시
	두 정수를 입력하세요 : 10 20
	AVG: 15.00
*/
int main(void) {
	int a=0, b=0;
	printf("두 정수를 입력하세요 : ");
	scanf_s("%d%d", &a, &b);
	printf("AVG: %.2f", (double)(a + b)/2);
	return 0;
}