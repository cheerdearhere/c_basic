#include <stdio.h>
#include "func.h"
//분할 컴파일: 다른 소스파일에서 가져옴
int CalculateFactorial(int);
// 헤더에 선언하는 경우: void GetFactorial(void) 없이 사용

//전역변수
int g_input = 10;
int main(void) {
	printf("from factorial.c: %d\n", CalculateFactorial(5));
	GetFactorial();

	//전역변수
	printf("main(): g_input - %d\n", g_input);
	return 0;
}