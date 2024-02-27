#include <stdio.h>
int main(void) {
	char* astrList[3] = { "Hello","World","String" };

	printf("astrList[i]\n");
	printf("%s\n", astrList[0]);
	printf("%s\n", astrList[1]);
	printf("%s\n", astrList[2]);

	printf("astrList[i]+1\n");
	printf("%s\n", astrList[0] + 1);
	printf("%s\n", astrList[1] + 2);
	printf("%s\n", astrList[2] + 3);

	printf("astrList[i][j]\n");
	printf("%c\n", astrList[0][3]);
	printf("%c\n", astrList[1][3]);
	printf("%c\n", astrList[2][3]);

	char aStrList[2][12] = { "Hello","World" };
	//char** pStrList = aStrList;
	char(*pStrList)[12] = aStrList;

	puts(pStrList[0]);
	puts(pStrList[1]);
	puts(pStrList[0] + 1);
	puts(pStrList + 1);

	return 0;
}