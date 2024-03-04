#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;

//USERDATA GetUserData(void) {
//	USERDATA user = { 0 };
//	scanf_s("%d%*c", &user.nAge);
//	gets_s(user.szName, sizeof(user.szName));
//	gets_s(user.szPhone, sizeof(user.szPhone));
//
//	return user;
//}

void GetUserData(USERDATA* pUser) {
	USERDATA user = { 0 };
	puts("회원정보를 입력합니다.\n나이: ");
	scanf_s("%d%*c", &pUser->nAge);
	puts("\n이름: ");
	gets_s(pUser->szName, sizeof(pUser->szName));
	puts("\n연락처: ");
	gets_s(pUser->szPhone, sizeof(pUser->szPhone));

	return;
}

int main(int argc, char* argv[]) {

	USERDATA user = { 0 };

	GetUserData(&user);

	printf("user: \n이름: %s, 나이: %d, 연락처: %s\n",
		user.szName, user.nAge, user.szPhone);

	return 0;
}
