#include <stdio.h>
#include <stdlib.h>

//����: �ǵ������� safe ó���� �ȵ� gets�� ����� ������Ȳ�� ������ ����
void GetString(void) {
	char szBuffer[8] = { 0 };
	int nData = 0x11223344;

	gets(szBuffer);
	printf("%s, %08X\n", szBuffer, nData);
	return;
}
int main(int argc, char* argv[]) {

	GetString();

	return 0;
}