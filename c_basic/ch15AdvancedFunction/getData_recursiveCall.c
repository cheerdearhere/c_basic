#include <stdio.h>

void putData(char* pszParam) {
	if (*pszParam == '\0') return;// 종료 문자 발견시 반복 멈춤
	putchar(*pszParam); // 출력
	putData(pszParam + 1); // 포인터 이동
}

int main(int argc, char* argv[]) {
	putData("TestData");
	putchar('\n');

	return 0;
}
