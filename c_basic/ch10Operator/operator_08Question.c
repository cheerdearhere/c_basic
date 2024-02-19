#include <stdio.h>
/*
문제2: 최대값 토너먼트
사용자로부터 입력받은 정수 중 가장 큰 수를 출력하는 프로그램을 작성
제한사항 
	정수는 부호가 있는 32비트 정수로 한정
	scanf_s 함수는 한 번만 사용
	최대값은 printf() 함수로 출력
출력 예시
	10 20 30
	MAX : 30
*/
int main(void) {
	int a = 0, b = 0, c = 0;
	scanf_s("%d%d%d", &a, &b, &c);
	a = (a > b) ? ((a > c) ? a : c) : b;
	printf("MAX : %d", a);
	return 0;
}
/*
오답노트: 
팁: 
	- 읽기 쉽게 나누는 것도 좋음
		int max = 0, a, b, c;
		...
		max = (a > b) ? a : b;
		max = (c > max) ? c : max;
		printf("MAX : %d", max);
*/