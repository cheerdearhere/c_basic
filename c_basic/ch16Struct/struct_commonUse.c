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
	puts("ȸ�������� �Է��մϴ�.\n����: ");
	scanf_s("%d%*c", &pUser->nAge);
	puts("\n�̸�: ");
	gets_s(pUser->szName, sizeof(pUser->szName));
	puts("\n����ó: ");
	gets_s(pUser->szPhone, sizeof(pUser->szPhone));

	return;
}

int main(int argc, char* argv[]) {

	USERDATA user = { 0 };

	GetUserData(&user);

	printf("user: \n�̸�: %s, ����: %d, ����ó: %s\n",
		user.szName, user.nAge, user.szPhone);

	return 0;
}
