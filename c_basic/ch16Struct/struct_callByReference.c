#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;

void GetUserData(USERDATA* userParam) {
	USERDATA user = {
		10, "Hoon", "010-1111-2222"
	};
	//memcpy(userParam, &user, sizeof(user));
	*userParam = user;//��������δ� ����
	return;
}


int main(int argc, char* argv[]) {

	USERDATA user = {
		20, "Joon", "010-3333-4444"
	};

	USERDATA result;
	GetUserData(&result);

	printf("result: \n�̸�: %s, ����: %d, ����ó: %s\n",
		result.szName, result.nAge, result.szPhone);

	return 0;
}
