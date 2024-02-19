#include <stdio.h>
/*
문제1 : 최댓값 서바이벌 
사용자로부터 입력 받은 정수 중 가장 큰 수를 출력하는 프로그램을 작성
제한사항
	정수는 부호가 있는 32비트 정수로 한정 
	scanf_s() 함수로 한번에 한 값만 입력
	내부적으로 초댓값을 계속 갱신하는 구조
출력 예시
	10
	20
	30
	MAX : 30
*/
int main(void) {
	int userInput = 0, max = 0;

	scanf_s("%d", &userInput);
	max = userInput;
	scanf_s("%d", &userInput);
	max = max < userInput ? userInput : max;
	scanf_s("%d", &userInput);
	max = max < userInput ? userInput : max;

	printf("MAX : %d", max);
	return 0;
}
/*
오답노트: 
팁: 
	- 간단하지만 매우 중요한 예제. 로직을 꼭 이해하자
*/