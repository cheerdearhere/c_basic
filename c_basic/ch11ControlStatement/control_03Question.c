#include <stdio.h>
/*
문제3: 버스 기본요금을 1000원으로 가정하고 나이에 따라 다음과 같이 할인율을 적용.
할인
	0~3		영유아		100%(무료)
	4~13	어린이		50%
	14~19	청소년		25%
	20~		성인			0%
출력 예시
	나이: 20
	요금: 1000
시작전 tip: 우선 2분할을 먼저하고 상세 분할로 나눈다
*/
int main(void) {
	int age = 0, fee = 1000;
	printf("나이 : ");
	scanf_s("%d", &age);

	if (age <= 13) {
		if (age <= 3) fee = 0;
		else fee *= 0.5;
	}
	else {
		if (age <= 19) fee *= 0.75;
	}

	printf("요금 : %d\n", fee);
	return 0;
}
/*
 오답노트:
 팁:
	- 이후 할인요율이 변경되는 것을 고려하면 변수를 나누는 것도 좋음
		int baseFee = 1000;
		double rate = 0.0;
		...
		if(age<4) rate = 0;
		...
		double fee = baseFee * rate;
		...

 */