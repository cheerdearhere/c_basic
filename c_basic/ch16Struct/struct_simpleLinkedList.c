#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
	struct USERDATA* pFront;// pointer
	struct USERDATA* pNext;// pointer 
} USERDATA;

void GetUserList(USERDATA* user) {

	printf("이름: %s, 나이: %d, 연락처: %s\n",
		user->szName,
		user->nAge,
		user->szPhone
	);
	if (user->pNext != NULL)
		GetUserList(user->pNext);
}

int main(int argc, char* argv[]) {

	USERDATA user1 = {
		18,
		"Hone",
		"010-1111-1234",
		NULL
	};
	USERDATA user2 = {
		25,
		"Jone",
		"010-2222-1234",
		NULL
	};
	USERDATA user3 = {
		13,
		"Cone",
		"010-3333-1234",
		NULL
	};

	user1.pNext = &user2;
	user2.pFront = &user1;
	user2.pNext = &user3;
	user3.pFront = &user2;

	GetUserList(&user1);

	return 0;
}
