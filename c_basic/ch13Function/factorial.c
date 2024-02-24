#include <stdio.h>
//int g_input = 3; 전역변수와 같은 이름으로 초기화하면 에러
//전역변수를 외부 파일에서 가져오는 경우(extern 생략도 가능하나 실수할 수 있으니..)
extern int g_input;

int CalculateFactorial(int nParam) {
	int nResult = 1, i = 0;
	for (i = 1; i <= nParam; i++) {
		nResult *= i;
	}
	//전역변수
	printf("other(): g_input - %d\n", g_input);
	return nResult;
}
void GetFactorial(void) {
	int nResult = 0, nInput = 0;
	printf("계승을 구할 정수(1 ~ 10)을 입력하세요: ");
	scanf_s("%d", &nInput);
	if (nInput < 1 || nInput > 10) {
		printf("ERROR: 1~10 사이의 정수를 입력해야합니다\n사용자 입력: %d\n",nInput);
	}
	else {
		nResult = CalculateFactorial(nInput);
		printf("%d! : %d\n", nInput, nResult);
	}
}
// 분할 컴파일을 위해 제외
//int main(void) {
//
//	GetFactorial();
//
//	return 0;
//}