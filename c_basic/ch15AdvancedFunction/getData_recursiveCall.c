#include <stdio.h>

void putData(char* pszParam) {
	if (*pszParam == '\0') return;// ���� ���� �߽߰� �ݺ� ����
	putchar(*pszParam); // ���
	putData(pszParam + 1); // ������ �̵�
}

int main(int argc, char* argv[]) {
	putData("TestData");
	putchar('\n');

	return 0;
}
