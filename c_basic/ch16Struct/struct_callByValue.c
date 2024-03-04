#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;

USERDATA GetUserData(USERDATA userParam) {

	printf("user: \n이름: %s, 나이: %d, 연락처: %s\n",
		userParam.szName,
		userParam.nAge,
		userParam.szPhone);
	USERDATA user = {
		10, "Hoon", "010-1111-2222"
	};
	return user;
}


int main(int argc, char* argv[]) {

	USERDATA user = {
		20, "Joon", "010-3333-4444"
	};
	USERDATA result;

	result = GetUserData(user);

	printf("result: \n이름: %s, 나이: %d, 연락처: %s\n",
		result.szName, result.nAge, result.szPhone);
	return 0;
}
