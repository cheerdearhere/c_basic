#include <stdio.h>

#define STRING(a) #a
#define PASTER(a, b) a##b

int main(int argc, char* argv[]) {

	int nData = 10; 

	printf("nData\t: %d\n", nData);
	printf("nDa##ta\t: %d\n", PASTER(nDa, ta));// 문자열이 아닌 소스코드 자체를 붙임
	printf("#nData\t: %s\n", STRING(nData));//"nData"

	return 0;
}