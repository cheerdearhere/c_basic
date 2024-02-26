#include <stdio.h>
int main(void) {
	char szBuffer[16] = { "Hello" };
	char* pszData = szBuffer; //싱글 포인터

	int nLength = 0;

	while (*pszData != '\0') {//제로 문자 발견전까지 이동
		pszData++;
		nLength++;
	}
	printf("&pszData: %p, &szBuffer: %p\n",
		pszData,
		szBuffer);// 메모리 주소
	printf("Length: %d\n", pszData - szBuffer); // 빼기 연산(산술아님)
	printf("Length: %d\n", nLength); // 계수 사용
	printf("Length: %d\n", strlen(szBuffer)); // strlen() 함수사용

	return 0;
}