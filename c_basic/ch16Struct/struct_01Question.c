#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
/*
간단한 연결리스트 예제(struct_simpleLinkedList.c)를 활용해 연결리스트 전체의 내용을 출력하는 함수 작성
제한사항
	함수의 매개변수로는 출력할 노드의 주소를 받음
	재귀호출을 통해 다음 노드로 이동하도록 구현
구조체
	typedef struct USERDATA {
		char szName[32];
		char szPhone[32];

		struct USERDATA* pFront;
		struct USERDATA* pNext;
	} USERDATA;
main
	USERDATA userList[4] = {
		{"김두식","1234",NULL},
		{"이미현","2345",NULL},
		{"김봉석","3456",NULL},
		{"장희수","4567",NULL},
	};
	userList[0].pNext = &userList[1];
	userList[1].pNext = &userList[2];
	userList[2].pNext = &userList[3];
	userList[3].pNext = NULL;
확인용 코드(실습에서는 제거)
	USERDATA* pUser;
	pUser = &userList[0];
	while (pUser != NULL) {
		printf("이름: %s, 연락처: %s\n",
			pUser->szName,
			pUser->szPhone
		);
		pUser = pUser->pNext;
	} 
*/
typedef struct USERDATA{
	char szName[32];
	char szPhone[32];

	struct USERDATA* pFront;
	struct USERDATA* pNext;
} USERDATA;

void PrintUserList(USERDATA* user) {
	printf("[%p] 이름: %s, 연락처: %s, pNext: %p\n",
		user,
		user->szName,
		user->szPhone,
		user->pNext
	);
	if (user->pNext != NULL) PrintUserList(user->pNext);
}

int main(void) {
	USERDATA userList[4] = {
		{"김두식","1234",NULL},
		{"이미현","2345",NULL},
		{"김봉석","3456",NULL},
		{"장희수","4567",NULL},
	};
	userList[0].pNext = &userList[1];
	userList[1].pNext = &userList[2];
	userList[2].pNext = &userList[3];
	userList[3].pNext = NULL;

	PrintUserList(userList);
	
	//USERDATA* pUser;
	//pUser = &userList[0];
	//while (pUser != NULL) {
	//	printf("이름: %s, 연락처: %s\n",
	//		pUser->szName,
	//		pUser->szPhone
	//	);
	//	pUser = pUser->pNext;
	//}

	return 0;
}
/*
오답노트: 
팁: 
	- 기왕이면 자료형을 표시하는 변수명 사용
		user -> pUser
	- 디버깅을 위해 포인터를 출력하는 것도 좋음
	printf("[%p] 이름: %s, 연락처: %s, pNext: %p\n",
		user,
		user->szName,
		user->szPhone,
		user->pNext
	);
	- 굳이 조건문을 쓰지 않아도 \0가 나오면 재귀함수가 움직이지 않음
		PrintUserList(user->pNext);
*/