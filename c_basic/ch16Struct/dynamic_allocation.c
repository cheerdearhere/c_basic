#include <stdio.h>
#include <string.h>

typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;


int main(int argc, char* argv[]) {
	
	USERDATA* pUser = NULL;
	//구조체의 포인터 변수 동적 할당
	pUser = (USERDATA*)malloc(sizeof(USERDATA));

	pUser->nAge = 10;
	strcpy_s(pUser->szName, sizeof(pUser->szName), "hgeee");
	strcpy_s(pUser->szPhone, sizeof(pUser->szPhone), "010-1111-1222");

	printf("user: \n이름: %s, 나이: %d, 연락처: %s\n",
		pUser->szName, pUser->nAge, pUser->szPhone);
	//할당 종료
	free(pUser);

	return 0;
}
