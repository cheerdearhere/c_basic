#include <stdio.h>
int main(void) {
	//FILE* fp = NULL;
	//
	//fopen_s(&fp, "Test.dat", "rb");

	//fseek(fp, 0, SEEK_END);
	//printf("size of Test.dat: %u\n", ftell(fp));
	//fclose(fp);

	FILE* fp = NULL;
	char* pszData = "01234567890123456789012345678901";//32byte

	fopen_s(&fp, "TestP.dat", "wb");
	if (fp == NULL) return;

	fwrite(pszData, 32, 1, fp);
	printf("current File pointer: %u\n", ftell(fp));

	fseek(fp, 5, SEEK_SET);//파일 포인터 이동
	printf("current File pointer: %u\n", ftell(fp));

	fwrite("Hello", 5, 1, fp);//현 위치부터 입력
	printf("current File pointer: %u\n", ftell(fp));

	fclose(fp);

	return 0;
}