#include <stdio.h>
#include <stdlib.h>
/*
문제: * 출력 응용
아래 예처럼 삼각형을 *로 출력하는 프로그램을 작성
그 후 이등변 삼각형 출력
제한사항
	for문 사용
	*의 왼쪽 여백은 tab으로 조절
출력예시
					*
				*	*
			*	*	*
		*	*	*	*
	*	*	*	*	*
					*
				*	*	*
			*	*	*	*	*
		*	*	*	*	*	*	*
	*	*	*	*	*	*	*	*	*
*/
int main(void) {
	// 역 직각
	for (int i = 5; i >= 1; i--) {
		for (int j = 1; j <= 5; j++) {
			if (i > j)
				printf("	");
			else
				printf("*	");
		}
		printf("\n");
	}
	// 이등변
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 + i; j++) {
			if (j >= 4 - i)
				printf("*	");
			else
				printf("	");
		}
		printf("\n");
	}
	return 0;
}
/*
오답노트:
팁:
	- 규칙을 찾기위해 행과 열을 나열해보자
		row		*위치
		0	+	4	= 4
		1	+	3
		2	+	2
		3	+	1
		4	+	0
	- 규칙을 찾았다면 조건문으로 간단하게 분기
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if(j >= 4 - i)
					printf("*	");
				else
					printf("	");
			}
			printf("\n");
		}
	- 별의 갯수를 생각하면 쉽게 도출 가능
*/