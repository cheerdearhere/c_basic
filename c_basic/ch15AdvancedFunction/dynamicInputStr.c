#include <stdio.h>


char* GetName(void) {
	char* pszName = NULL;
	pszName = (char*)calloc(32, sizeof(char));//동적할당
	printf("이름을 입력하세요: ");
	fgets(pszName, sizeof(char) * 32, stdin); //리눅스에서 사용
	// == gets_s()

	return pszName;
}
int main(int argc, char* argv[]) 
	char* pszName = NULL;
	pszName = GetName();
	//Callee에서 동적할당한 메모리 pszName은 stack frame 제거와 함께 사라짐
	printf("당신의 이름은 %s 입니다.\n", pszName);

	//Collee가 없으므로 할당 해제의 책임은 Caller
	free(pszName);

	return 0;
}
