#include <stdio.h>
#include <stdlib.h>
/*
문제: 
문제2: 총합 출력
1~10까지 총합을 출력하는 프로그램을 작성.
제한사항
	while문과 for문으로 각각 작성
	반복회수는 10회
	총합을 누적하는 변수를 활용
출력예시
	Total: 55
*/
int main(void) {
	int totalw = 0, i = 1;
	while (i <= 10) {
		totalw += i;
		i++;
	}
	printf("while total: %d\n", totalw);


	int totalf = 0;
	for (int j = 0; j < 10; j++) {
		totalf += (j + 1);
	}
	printf("for total: %d\n", totalf);
	return 0;
}
/*
오답노트:
팁: 
*/