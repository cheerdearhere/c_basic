#include <stdio.h>
int main(void) {
	char ch = 'A'; // ¿øº»
	char* pData = &ch; // pointer
	char** ppData = &pData; // pointer to pointer
	char*** pppData = &ppData; // pointer to pointer to pointer

	printf("origin:\t %c\t[%p]\n", ch, &ch);
	printf("*:\t %c\t[%p]\n", *pData, &pData);
	printf("**:\t %c\t[%p]\n", **ppData, &ppData);
	printf("***:\t %c\t[%p]\n", ***pppData, &pppData);


	return 0;
}