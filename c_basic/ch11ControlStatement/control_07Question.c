#include <stdio.h>
#include <stdlib.h>
/*
문제: 정사각형 출력
5행 5열 사각형을 *로 출력하는 프로그램 작성
그후 대각선으로 나눈 삼각형을 출력
제한사항
	for문 사용
출력예시
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	
	*	*	
	*	*	*	
	*	*	*	*
	*	*	*	*	*
*/
int main(void) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("* ");
		}
		printf("\n");
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
/*
오답노트:
팁: 
*/