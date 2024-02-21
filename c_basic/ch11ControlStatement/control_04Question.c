#include <stdio.h>
#include <stdlib.h>
/*
문제: 
사용자로부터 정수를 입력받아 그 수만큼 '*'를 출력하는 프로그램을 작성. 
사용자 입력이 범위를 넘어서면 강제로 보정
제한사항
	1~9 범위의 정수를 입력
	*은 한 행에 이어서 출력하고 전체 출력이 끝나면 개행
출력예시
	3
	* * *
	5
	* * * * *
*/
int main(void) {
	int i = 0;
	while (i < 1 || i > 9) {
		printf("1~9사이의 정수를 입력하세요.\n");
		scanf_s("%d", &i);
	}
	while (i > 0) {
		putchar('*');
		--i;
		if (i == 0) {
			putchar("\n");
			break;
		}
	}
	puts("END");
	return 0;
}
/*
오답노트:
팁: 
- input과 i를 따로 넣는 것도 방법
	while(i<input){
		putchar('*');
		++i;
	}
	putchar("\n");
- printf()로 형식문자 사용하면 보기 편함
	printf("*\t");
*/