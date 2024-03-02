#include <stdio.h>
#include <stdlib.h>

//주의: 의도적으로 safe 처리가 안된 gets를 사용해 에러상황을 구현한 예제
void GetString(void) {
	char szBuffer[8] = { 0 };
	int nData = 0x11223344;

	gets(szBuffer);
	printf("%s, %08X\n", szBuffer, nData);
	return;
}
int main(int argc, char* argv[]) {

	GetString();

	return 0;
}