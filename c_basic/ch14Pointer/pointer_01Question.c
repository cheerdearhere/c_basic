/*
아래 코드의 결함에 대해 말하고 바르게 수정하시오
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char szBuffer[12] = { "HelloWorld" };
	char* pszData = NULL;
	pszData = (char*)malloc(sizeof(char) * 12);
	pszData = szBuffer;
	puts(pszData);

	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
// add library 
#include <string.h>
int main(void) {
	char szBuffer[12] = { "HelloWorld" };
	char* pszData = NULL;
	pszData = (char*)malloc(sizeof(char) * 12);
	//단순 복사는 불가
//	pszData = memcpy(pszData, szBuffer, 12);
	for (int i = 0; i < 12; i++)
		pszData[i] = szBuffer[i];
	puts(pszData);
	//메모리 할당 해제
	free(pszData);

	return 0;
}
/*
오답노트:
	- 메모리 할당 해제 안함
		free(pszData);
팁: 
*/