#include <stdio.h>
/*
문제1 
사용자로부터 입력 받은 정수 중 가장 큰 수를 출력하는 프로그램을 작성. 
제한사항
	정수는 부호가 있는 32비트 정수로 한정
	scanf_s함수로 한번에 한 값만 입력
	내부적으로 최댓값을 계속 갱신하는 구조로 작성
	if문 사용
출력 예시
	10
	20
	30
	MAX : 30
*/
int main(void) {
	int nInput = 0, max = 0;

	scanf_s("%d", &nInput);
	max = nInput;
	scanf_s("%d", &nInput);
	if (max < nInput) max = nInput;
	scanf_s("%d", &nInput);
	if (max < nInput) max = nInput;

	printf("MAX : %d\n", max);

	return 0;
}/*
 오답노트:
 팁: 
 */