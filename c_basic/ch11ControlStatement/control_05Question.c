#include <stdio.h>
#include <stdlib.h>
/*
문제1: 구구단
1~9단의 구구단표 출력
출력예시
	###1단 시작
	1 X 1 = 1
	...
	### 1단 끝
*/
int main(void) {
	for (int i = 1; i <= 9; i++) {
		printf("%d단 시작\n", i);
		for (int j = 1; j <= 9; j++) {
			printf("%d X %d = %d\n", i, j, i * j);
		}
		printf("%d단 끝\n", i);
	}
	return 0;
}
/*
오답노트:
팁: 
*/