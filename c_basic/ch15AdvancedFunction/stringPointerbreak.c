#include <stdio.h> 
#include <string.h>

void main(int argc, char* argv[]) {
	// 구문 분석하기
	char szBuffer[128] = { 0 };
	char szSet[128] = { 0 };
	char* pszStart = szBuffer;// szBuffer의 0번째 요소를 지칭하는 포인터

	printf("Input string: ");
	gets_s(szBuffer, sizeof(szBuffer)); // 입렵받은 버퍼

	printf("Input character set: ");
	gets_s(szSet, sizeof(szSet)); // 구분자로 사용할 문자열

	long long index = 0;
	// 
	while ((pszStart = strpbrk(pszStart, szSet)) != NULL)
	{
		index = pszStart - szBuffer;
		printf("[%p] Index: %lld, %c\n",
			pszStart,/*찾은 주소*/
			index,/* 찾은 거리*/
			*pszStart /*대상*/);

		pszStart++; // 포인터 이동
	}

	/*
		콘솔)
		Input string: Test string data
		Input character set: sa
		[001CFA2E] Index: 2, s
		[001CFA31] Index: 5, s
		[001CFA39] Index: 13, a
		[001CFA3B] Index: 15, a
	*/

}
