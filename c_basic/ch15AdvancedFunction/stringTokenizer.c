#include <stdio.h>
#include <string.h>



int main(int argc, char* argv[]) {
	//String tokenizer 함수 사례
		// 버퍼
	char szBuffer[128] = { "nData = x + y; \nnResult = a * b" };
	// 구분자 지정: 공백, 연산자, \n
	char* pszSep = " *+=;\n";
	char* pszToken = NULL;
	char* pszNextToken = NULL;
	//strtok_s(대상 문자열, separator, 처리할 토큰을 가리키는 포인터)
	pszToken = strtok_s(szBuffer, pszSep, &pszNextToken);
	// 내부적으로 정적변수를 쓰다보니 멀티스레딩 관련 이슈가 있었으나
	// 스레드 로컬 스토리지 기법으로 해결됨
	while (pszToken != NULL) {
		puts(pszToken);
		pszToken = strtok_s(NULL, pszSep, &pszNextToken);
		//대상 메모리의 값을 00(null)로 변환
	}
	printf("\nszBuffer: %s\n", szBuffer);
	//원본 버퍼에도 영향을 줌

	return 0;
}
