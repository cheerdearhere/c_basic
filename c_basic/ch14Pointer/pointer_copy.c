#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char szBuffer[12] = { "HelloWorld" };
	char szNewBuffer[12] = { 0 };

	//szNewBuffer = szBuffer; 
	//		붙여 넣을,	가져올,	크기
	memcpy(szNewBuffer, szBuffer, 4);

	printf("origin: ");
	for (int i = 0; i < 12; i++)
		printf("%c\t", szBuffer[i]);
	putchar('\n');

	printf("copy: ");
	for (int i = 0; i < 12; i++)
		printf("%c\t", szNewBuffer[i]);
	putchar('\n');

	return 0;
}