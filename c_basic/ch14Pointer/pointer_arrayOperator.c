#include <stdio.c>
int main(void) {
	char szBuffer[32] = { "You are a girl." };

	printf("szBuffer[0]: %c\n", szBuffer[0]);
	printf("*szBuffer: %c\n", *szBuffer);
	printf("*(szBuffer + 0): %c\n", *(szBuffer + 0));

	printf("szBuffer[5]: %c\n", szBuffer[5]);
	printf("*(szBuffer + 5): %c\n", *(szBuffer + 5));
	printf("*szBuffer + 5: %c\n", *szBuffer + 5);

	printf("&szBuffer[4]: %s\n", &szBuffer[4]);
	printf("&*(szBuffer + 4): %s\n", &*(szBuffer + 4));
	printf("szBuffer + 4(str): %s\n", szBuffer + 4);
	printf("szBuffer + 4(pointer): %p\n", szBuffer + 4);

	return 0;
}