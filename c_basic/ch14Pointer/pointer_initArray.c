#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char szBuffer[] = { "Hello" };
	char* pszBuffer = "Hello";
	char* pszData = NULL;

	pszData = (char*)malloc(sizeof(char) * 6);
	pszData[0] = 'H';
	pszData[1] = 'e';
	pszData[2] = 'l';
	pszData[3] = 'l';
	pszData[4] = 'o';
	pszData[5] = '\0';

	puts(szBuffer);
	puts(pszBuffer);
	puts(pszData);

	free(pszData);



	int* pList = NULL, * pNewList = NULL;
	int aList[3] = { 0 };

	pList = (int*)malloc(sizeof(int) * 3);
	memset(pList, 0, sizeof(int) * 3);

	pNewList = (int*)calloc(3, sizeof(int));

	for (int i = 0; i < 3; ++i)
		printf("pList[%d]의 값: %d\t", i, pList[i]);
	putchar('\n');
	for (int i = 0; i < 3; ++i)
		printf("pNewList[%d]의 값: %d\t", i, pNewList[i]);
	putchar('\n');

	free(pList);
	free(pNewList);

	return 0;
}