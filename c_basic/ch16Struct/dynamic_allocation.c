#include <stdio.h>
#include <string.h>

typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;


int main(int argc, char* argv[]) {
	
	USERDATA* pUser = NULL;
	//����ü�� ������ ���� ���� �Ҵ�
	pUser = (USERDATA*)malloc(sizeof(USERDATA));

	pUser->nAge = 10;
	strcpy_s(pUser->szName, sizeof(pUser->szName), "hgeee");
	strcpy_s(pUser->szPhone, sizeof(pUser->szPhone), "010-1111-1222");

	printf("user: \n�̸�: %s, ����: %d, ����ó: %s\n",
		pUser->szName, pUser->nAge, pUser->szPhone);
	//�Ҵ� ����
	free(pUser);

	return 0;
}
