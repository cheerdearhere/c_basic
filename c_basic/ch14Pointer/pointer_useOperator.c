#include <stdio.h>
int main(void) {

	char szBuffer[16] = { "Hello" };
	char* pszData = szBuffer; //싱글 포인터

	while (*pszData != '\0') //제로 문자 발견전까지 이동
		pszData++;
	printf("&pszData: %p, &szBuffer: %p\n",
		pszData,
		szBuffer);// 메모리 주소
	printf("Length: %d\n", pszData - szBuffer); // 빼기 연산(산술아님)

	return 0;
}