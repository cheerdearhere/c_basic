#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
/*
������ ���Ḯ��Ʈ ����(struct_simpleLinkedList.c)�� Ȱ���� ���Ḯ��Ʈ ��ü�� ������ ����ϴ� �Լ� �ۼ�
���ѻ���
	�Լ��� �Ű������δ� ����� ����� �ּҸ� ����
	���ȣ���� ���� ���� ���� �̵��ϵ��� ����
����ü
	typedef struct USERDATA {
		char szName[32];
		char szPhone[32];

		struct USERDATA* pFront;
		struct USERDATA* pNext;
	} USERDATA;
main
	USERDATA userList[4] = {
		{"��ν�","1234",NULL},
		{"�̹���","2345",NULL},
		{"�����","3456",NULL},
		{"�����","4567",NULL},
	};
	userList[0].pNext = &userList[1];
	userList[1].pNext = &userList[2];
	userList[2].pNext = &userList[3];
	userList[3].pNext = NULL;
Ȯ�ο� �ڵ�(�ǽ������� ����)
	USERDATA* pUser;
	pUser = &userList[0];
	while (pUser != NULL) {
		printf("�̸�: %s, ����ó: %s\n",
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
	printf("[%p] �̸�: %s, ����ó: %s, pNext: %p\n",
		user,
		user->szName,
		user->szPhone,
		user->pNext
	);
	if (user->pNext != NULL) PrintUserList(user->pNext);
}

int main(void) {
	USERDATA userList[4] = {
		{"��ν�","1234",NULL},
		{"�̹���","2345",NULL},
		{"�����","3456",NULL},
		{"�����","4567",NULL},
	};
	userList[0].pNext = &userList[1];
	userList[1].pNext = &userList[2];
	userList[2].pNext = &userList[3];
	userList[3].pNext = NULL;

	PrintUserList(userList);
	
	//USERDATA* pUser;
	//pUser = &userList[0];
	//while (pUser != NULL) {
	//	printf("�̸�: %s, ����ó: %s\n",
	//		pUser->szName,
	//		pUser->szPhone
	//	);
	//	pUser = pUser->pNext;
	//}

	return 0;
}
/*
�����Ʈ: 
��: 
	- ����̸� �ڷ����� ǥ���ϴ� ������ ���
		user -> pUser
	- ������� ���� �����͸� ����ϴ� �͵� ����
	printf("[%p] �̸�: %s, ����ó: %s, pNext: %p\n",
		user,
		user->szName,
		user->szPhone,
		user->pNext
	);
	- ���� ���ǹ��� ���� �ʾƵ� \0�� ������ ����Լ��� �������� ����
		PrintUserList(user->pNext);
*/