#include <stdio.h> 
#include <string.h>

void main(int argc, char* argv[]) {
	// ���� �м��ϱ�
	char szBuffer[128] = { 0 };
	char szSet[128] = { 0 };
	char* pszStart = szBuffer;// szBuffer�� 0��° ��Ҹ� ��Ī�ϴ� ������

	printf("Input string: ");
	gets_s(szBuffer, sizeof(szBuffer)); // �Էƹ��� ����

	printf("Input character set: ");
	gets_s(szSet, sizeof(szSet)); // �����ڷ� ����� ���ڿ�

	long long index = 0;
	// 
	while ((pszStart = strpbrk(pszStart, szSet)) != NULL)
	{
		index = pszStart - szBuffer;
		printf("[%p] Index: %lld, %c\n",
			pszStart,/*ã�� �ּ�*/
			index,/* ã�� �Ÿ�*/
			*pszStart /*���*/);

		pszStart++; // ������ �̵�
	}

	/*
		�ܼ�)
		Input string: Test string data
		Input character set: sa
		[001CFA2E] Index: 2, s
		[001CFA31] Index: 5, s
		[001CFA39] Index: 13, a
		[001CFA3B] Index: 15, a
	*/

}
