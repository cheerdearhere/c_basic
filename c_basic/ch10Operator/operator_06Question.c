#include <stdio.h>
/*
사용자로부터 점수(0~100)를 입력받아
80점 이상이면 '합격' 그렇지 않으면 '불합격'이라고 출력하는 프로그램을 작성.
반드시 3항 연산자를 사용
출력 예시
	점수를 입력하세요 : 80
	결과: 합격
*/
int main(void){
	int score = 0;
	printf("점수를 입력하세요: ");
	scanf_s("%d", &score);

	printf("결과: %s\n", 
		(score >= 80) ? "합격" : "불합격"
	);

	return 0;
}
/*
오답노트: 
팁: 
	- 보기 좋게 행 구분하는 것도 좋음
*/