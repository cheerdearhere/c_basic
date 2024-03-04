#include <stdio.h>
#include <string.h>


typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;


int main(int argc, char* argv[]) {
	USERDATA user = { 0, "", "" };

	user.nAge = 10;

	strcpy_s(user.szName, sizeof(user.szName), "Hong gil done");
	strcpy_s(user.szPhone, sizeof(user.szPhone), "010-1234-1234");

	printf("user: \n이름: %s, 나이: %d, 연락처: %s\n", user.szName, user.nAge, user.szPhone);

	return 0;
}
