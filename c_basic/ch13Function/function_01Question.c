#incluide <stdio.c>
/*
문제: 사용자로부터 세 정수를 입력받아 최대값을 반환하는 프로그램
제한사항
	사용자 입력과 최댓값 계산 코드를 별도 함수로 분리
출력예시
	(입력은 자유롭게, 사용자 친화적으로)
	MAX: 5
작성 팁
	함수 원형부터 생각해보자
	함수 원형(함수 시그니처): 
		returnType methodName(parameterType paramterName, ...)
*/
int CalcMax(int a, int b, int c) {
	int nMax = a;
	if (b > nMax) nMax = b;
	if (c > nMax) nMax = c;

	return nMax;
}
void GetMax(void) {
	int a, b, c;
	puts("세 정수를 입력해주세요(a b c): ");
	scanf_s("%d%d%d",&a,&b,&c);
	printf("MAX: %d\n", CalcMax(a, b, c));
}
int main(void) {
	
	GetMax();

	return 0;
}
/*
오답노트:
팁: 
*/