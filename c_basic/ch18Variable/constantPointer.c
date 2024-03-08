#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintString(const char* pszParam) {
	puts(pszParam);
}

int main(int argc, char* argv[]) {
	char szBuffer[32] = {"I am a boy."};
	const char* pszBuffer = szBuffer;//szBuffer[0]의 메모리 
	szBuffer[0] = 'i';
	//*pszBuffer = 'i';//에러

	PrintString(szBuffer);
	PrintString("You are a girl.");

	int nData = 10;
	
	const int* pnData = &nData;
	//*pnData = 20; 주소는 변경할 수 없음
	pnData = 20;

	int* const pnNewData = &nData;
	//pnNewData = NULL; 변수에대한 대입 자체가 불가

	return 0;
}