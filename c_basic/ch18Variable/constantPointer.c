#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintString(const char* pszParam) {
	puts(pszParam);
}

int main(int argc, char* argv[]) {
	char szBuffer[32] = {"I am a boy."};
	const char* pszBuffer = szBuffer;//szBuffer[0]�� �޸� 
	szBuffer[0] = 'i';
	//*pszBuffer = 'i';//����

	PrintString(szBuffer);
	PrintString("You are a girl.");

	int nData = 10;
	
	const int* pnData = &nData;
	//*pnData = 20; �ּҴ� ������ �� ����
	pnData = 20;

	int* const pnNewData = &nData;
	//pnNewData = NULL; ���������� ���� ��ü�� �Ұ�

	return 0;
}