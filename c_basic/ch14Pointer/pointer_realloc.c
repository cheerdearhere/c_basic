#include <stdio.h>
#include <string.h>
int main(void) {

	char* pszBuffer = NULL, * pszNewBuffer = NULL;

	pszBuffer = (char*)malloc(12);// 12����Ʈ ��û
	sprintf_s(pszBuffer, 12, "%s", "TestString");

	printf("[%p] %zd %s\n",
		pszBuffer,
		_msize(pszBuffer),
		pszBuffer
	);

	pszNewBuffer = (char*)realloc(pszBuffer, 32);
	//32����Ʈ�� Ȯ�� ��û

	sprintf_s(pszNewBuffer, 32, "%s", "TestStringData");
	printf("[%p] %zd %s\n",
		pszNewBuffer,
		_msize(pszNewBuffer),
		pszNewBuffer
	);

	free(pszNewBuffer);
	return 0;
}