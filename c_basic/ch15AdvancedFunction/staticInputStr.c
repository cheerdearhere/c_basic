#include <stdio.h>
void GetName(char* pszName, unsigned int nSize) {
	printf("�̸��� �Է��ϼ���: ");
	gets_s(pszName, nSize);
}

int main(int argc, char* argv[]) {

	char szName[32] = { 0 };
	GetName(szName, sizeof(szName));
	printf("����� �̸��� %s �Դϴ�.\n", szName);

	return 0;
}