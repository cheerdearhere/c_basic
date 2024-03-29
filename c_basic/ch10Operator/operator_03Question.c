#include <stdio.h>
/*
두 변수의 값을 교환하는 코드를 작성
사용자로부터 두 정수를 입력받아 각각을 int형 변수 a, b에 저장하고
임시 변수 tmp를 활용해 a, b의 값을 교환한 후 출력하는 프로그램을 작성
출력 예시
	두 정수를 입력해주세요: 3 4
	a: 4, b: 3
*/
int main(void) {
	int a = 0, b = 0;
	printf("두 정수를 입력해주세요: ");
	scanf_s("%d%d", &a, &b);

	int temp = a;
	a = b;
	b = temp;

	printf("a: %d, b: %d", a, b);
	return 0;
/*
오답노트: 
팁: 이처럼 임시값을 사용할때 마치 값의 이동이 신발끈모양처럼 좌하향하는 모습을 보고 '신발끈 공식'이라 한다
*/
}