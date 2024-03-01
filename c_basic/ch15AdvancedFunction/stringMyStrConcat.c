#include <stdio.h>
char* mystrcat(char* pszDst, char* pszSrc) {//목적지 주소에 입력
	while (*pszDst != '\0') //문자배열의 해당 포인터가 null이 아니면
		++pszDst;// 목적지의 마지막으로 이동

	while (*pszSrc != '\0')
		*pszDst++ = *pszSrc++;

	// 복사 후 하나씩 증가(후위식 증감)
	*++pszDst = '\0';// 원본의 끝에 닿으면 복사 목적지의 마지막 index 다음에 null입력
	return --pszDst;//이전 포인터 반환
}


int main(int argc, char* argv[]) {

	char szPath[128] = { 0 };
	char* pszEnd = NULL;

	//char szPath[]의 주소를 사용하므로 원본에 영향을 줌
	pszEnd = mystrcat(szPath, "C:\\Program Files\\");
	pszEnd = mystrcat(pszEnd, "CHS\\");
	pszEnd = mystrcat(pszEnd, "C programming");

	puts(szPath);

	return 0;
}
