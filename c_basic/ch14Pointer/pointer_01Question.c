/*
�Ʒ� �ڵ��� ���Կ� ���� ���ϰ� �ٸ��� �����Ͻÿ�
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char szBuffer[12] = { "HelloWorld" };
	char* pszData = NULL;
	pszData = (char*)malloc(sizeof(char) * 12);
	pszData = szBuffer;
	puts(pszData);

	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
// add library 
#include <string.h>
int main(void) {
	char szBuffer[12] = { "HelloWorld" };
	char* pszData = NULL;
	pszData = (char*)malloc(sizeof(char) * 12);
	//�ܼ� ����� �Ұ�
//	pszData = memcpy(pszData, szBuffer, 12);
	for (int i = 0; i < 12; i++)
		pszData[i] = szBuffer[i];
	puts(pszData);
	//�޸� �Ҵ� ����
	free(pszData);

	return 0;
}
/*
�����Ʈ:
	- �޸� �Ҵ� ���� ����
		free(pszData);
��: 
*/