#include <stdio.h>
int main(void) {
	int nResult = 0;
	nResult = 3 / 4;

	printf("nResult(-5) : %d \n", nResult - 5);// 값 저장없이 이용만 해도됨
	printf("nResult : %d\n", nResult);//이 경우에 변수에 저장된 값에 write가 처리되지 않음

	return 0;
}