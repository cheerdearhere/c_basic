#include <stdio.h>

// global(static) variable 
int g_nCounter = 0;
// 데이터를 다루는 function
void InitCounter(int nData) {
	g_nCounter = nData;
}
void IncreaseCounter(void) {
	g_nCounter++;
}

int main(void) {
	//내부에 선언이 없어도 동작...
	//편해보이겠지만 다른 모든 함수가 접근하기에 위험
	InitCounter(10);
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
	return 0;
}
