#include <stdio.h>
#include <string.h>
/*
두 char[]의 주소를 매개변수로 받아 문자열을 Deap copy하는 MyStrcpy() 작성
함수의 두번째 매개변수는 첫번째 매개변수의 메모리 크기가 되도록 구현
	int main(int argc, char* argv[]) {
		char szBufferSrc[12] = { "TestString" };
		char szBufferDst[12] = { 0 };

		MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
		puts(szBufferDst);
		return 0;
	}
출력 예시
	TestString
*/
void MyStrcpy(char* targetArr, int length, char* sorceArr) {
	size_t nLenSrc = 0;
	nLenSrc = strlen(targetArr);

	for (int i = 0; i < nLenSrc; i++)
		targetArr[i] = sorceArr[i];
}


int main(int argc, char* argv[]) {
	char szBufferSrc[12] = { "TestString" };
	char szBufferDst[12] = { 0 };

	MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
	puts(szBufferDst);
	return 0;
}
/*
오답노트:
	- 좀 더 정확한 매개변수는 size에 unsigned int형 사용
		void MyStrcpy(char* targetArr, unsigned int length, char* sorceArr) {

팁: 
	- 원 자료와 대상의 크기를 비교해 체크해야한다(대상의 사이즈를 인수로 받는 이유). 
		if (nLenSrc + 1 > length) {
		// exception: 다만 아직 예외처리를 학습하지 않았으므로 생략
		return;
	}
	- strlen(char*)를 쓰지 않아도 구현은 된다. 
		- 하지만 대상 메모리 크기가 12바이트고 원본이 5바이트면 7바이트 만큼의 쓰레기 값이 복사된다
		- 이 쓰레기 값은 오류를 발생시키므로 Deep copy는 맞으나 적절한 복사라 할 수 없다.
	size_t nLenSrc = 0;
	nLenSrc = strlen(targetArr);
*/ 