#include <stdio.h>
#include <string.h>
int main(void) {

	char szBuffer[12] = { "TestString" };
	char* pszData = "TestString";

	printf("%d\n", strcmp(szBuffer, pszData));
	printf("%d\n", strcmp("TestString", pszData));
	printf("%d\n", memcmp("TestString", pszData, sizeof(pszData)));
	printf("%d\n", strcmp("Test", "TestString"));

	char strBuffer[32] = { "I am a boy" };

	printf("%p\n", strBuffer);
	printf("am: %p\n", strstr(strBuffer, "am"));
	printf("boy: %p\n", strstr(strBuffer, "boy"));
	printf("zzz: %p\n", strstr(strBuffer, "zzz"));

	printf("index(am): %d\n", strstr(strBuffer, "am") - strBuffer);
	printf("index(boy): %d\n", strstr(strBuffer, "boy") - strBuffer);

	return 0;
}